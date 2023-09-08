#include "head.h"
#include <thread>
#include <atomic>
#include <mutex>

std::mutex m;

// long cnt = 0;
std::atomic<long> cnt(0);
// std::atomic_long cnt(0);

void counter()
{
    for (int i = 0 ; i < 100000; i++)
    {
        //std::lock_guard<std::mutex> lk(m);
        cnt += 1;
    }
}

struct A {
    int x;
};


struct B {
    int x, y;  // lock free false
};

struct C {
    int x;
    int y;
};

struct D {
    int x;
    int y;
    int z;
};

int main()
{
    // test is_lock_free()
    std::cout << std::boolalpha << "cnt is lock free? " << cnt.is_lock_free() << std::endl;
    std::cout << std::boolalpha << "std::atomic<A> is lock free? " << std::atomic<A>{}.is_lock_free() << std::endl;
    std::cout << std::boolalpha << "std::atomic<B> is lock free? " << std::atomic<B>{}.is_lock_free() << std::endl;
    std::cout << std::boolalpha << "std::atomic<C> is lock free? " << std::atomic<C>{}.is_lock_free() << std::endl;
    std::cout << std::boolalpha << "std::atomic<D> is lock free? " << std::atomic<D>{}.is_lock_free() << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::thread threads[100];
    for (int i = 0; i < 100; i++) {
        threads[i] = std::thread(counter);
    }

    for (auto &t : threads)
        t.join();
    
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = t2 - t1;

    std::cout << "result: " << cnt << std::endl;

    std::cout << "duration: " << elapsed.count() << " ms" << std::endl;

    return 0;
}



/*
cnt is lock free? true 
std::atomic<A> is lock free? true 
std::atomic<B> is lock free? true 
std::atomic<C> is lock free? true 
std::atomic<D> is lock free? false 
result: 10000000 
duration: 407.862 ms
*/