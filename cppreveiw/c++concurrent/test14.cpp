#include <iostream>
#include <thread>
#include <future>
#include <functional>



//test package_task
// https://en.cppreference.com/w/cpp/thread/packaged_task
int f(int x, int y) { return x + y; }


void task_lambda()
{
    std::packaged_task<int(int, int)> task([](int a, int b){
        return a + b;
    });
    std::future<int> result = task.get_future();

    task(2, 9); // 如果不执行task， result.get()看起来是阻塞的
    std::cout << "hahaha" << std::endl;
    std::cout << "task_lambda:\t" << result.get() << std::endl;
}

void task_bind()
{
    std::packaged_task<int(int)> task(std::bind(f, std::placeholders::_1, 11));
    std::future<int> result = task.get_future();
    task(2);
    std::cout << "task_bind:\t" << result.get() << std::endl;
}


void task_thread()
{
    std::packaged_task<int(int, int)> task(f);

    std::future<int> result = task.get_future();

    std::thread task_t(std::move(task), 2, 10);  // 这里为什么要move

    task_t.join();
    std::cout << "task_thread:\t" << result.get() << std::endl;

}


std::function<int(int, int)> f2(std::bind(f, std::placeholders::_1, std::placeholders::_2));

int main()
{
    std::cout << "=====test package_task======" << std::endl;
    task_lambda();
    task_bind();
    task_thread();
    std::cout << "=====test move======" << std::endl;
    std::cout << f2(3,4) << std::endl;
    std::function<int(int, int)> f3 = std::move(f2);
    std::cout << f3(1,2) << std::endl;
    // f2(1,2);  
    /*
        terminate called after throwing an instance of 'std::bad_function_call'
        what():  bad_function_call
    */
    
    return 0;
}

