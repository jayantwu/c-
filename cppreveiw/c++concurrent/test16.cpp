// https://en.cppreference.com/w/cpp/thread/shared_future
#include <iostream>
#include <future>
#include <chrono>
 
int main()
{   
    std::promise<void> ready_promise, t1_ready_promise, t2_ready_promise;
    std::shared_future<void> ready_future(ready_promise.get_future()); // 移动构造 shared_future
 
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
 
    auto fun1 = [&, ready_future]() -> std::chrono::duration<double, std::milli> 
    {
        t1_ready_promise.set_value();
        ready_future.wait(); // waits for the signal from main()
        return std::chrono::high_resolution_clock::now() - start;
    };
 
 
    auto fun2 = [&, ready_future]() -> std::chrono::duration<double, std::milli> 
    {
        t2_ready_promise.set_value();
        ready_future.wait(); // waits for the signal from main()
        return std::chrono::high_resolution_clock::now() - start;
    };
 
    auto fut1 = t1_ready_promise.get_future(); // fut1 是一个std::future
    auto fut2 = t2_ready_promise.get_future();
 
    auto result1 = std::async(std::launch::async, fun1); // 异步执行 fun1， 将返回future<std::chrono::duration<double, std::milli> > 对象
    auto result2 = std::async(std::launch::async, fun2); // 异步执行 fun2
 
    // wait for the threads to become ready， 目的就是等两个线程都执行起来， 并阻塞在wait上
    fut1.wait();   // 当 t1_ready_promise.set_value(); 执行后， wait 返回
    fut2.wait();   // 当 t2_ready_promise.set_value(); 执行后， wait 返回
 
    // the threads are ready, start the clock
    start = std::chrono::high_resolution_clock::now();  //记录当前时间
 
    // signal the threads to go
    ready_promise.set_value(); // 设置之后， 两个线程的ready_future.wait()都将返回，计算时间差， 但实际有先后， 将在下面打印出各自的时间
 
    std::cout << "Thread 1 received the signal "
              << result1.get().count() << " ms after start\n"
              << "Thread 2 received the signal "
              << result2.get().count() << " ms after start\n";
}