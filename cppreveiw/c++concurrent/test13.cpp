#include "test13.hpp"
#include <iostream>
#include <vector>
#include <chrono>

// 四个线程， 处理8个任务

int main()
{
    ThreadPool pool(4);  // 启动了4个线程
    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; i++)  // 8个任务
    {
        results.emplace_back(
            pool.enqueue([i]() {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
            }
            )
        );
    }


    for (auto && result : results)
    {
        std::cout << result.get() << " ";
    }
    std::cout << std::endl;
    return 0;
}


