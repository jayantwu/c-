#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include "utils.hpp"


// usege of std::promise

void print_int(std::future<int>  &fut)
{
    std::cout << "value is " << fut.get() << std::endl;
}

void do_work(std::promise<void> barrier)
{
    for (auto i = 0; i < 3; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "sleep.." << std::endl;
    }
    barrier.set_value(); //barrier_fut.wait()将返回
}


int main()
{
    std::promise<int> prom;
    // check_lr(prom.get_future());
    // check_lr(3);
    // int a = 3;
    // check_lr(a);
    std::future<int> fut = prom.get_future(); // 应该是调了future的移动构造函数
    
    std::thread t(print_int, std::ref(fut));   //将fut交给另一个线程   // 这里使用std::ref 是因为print_int 定义时 参数是传引用， 如果是传值 就要用std::move
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    prom.set_value(10);    // 设置共享状态的值， fut.get() 将返回
    
    t.join();


    std::promise<void> barrier;
    std::future<void>  barrier_fut = barrier.get_future();
    std::thread t2(do_work, std::move(barrier));      // 这里使用std::move 是因为 do_work 是传值的，promise 不可拷贝， 所以移动
    barrier_fut.wait();  // 当t2执行时， set_value之后， 将返回
    t2.join();


    return 0;
}

