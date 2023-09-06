// https://github.com/progschj/ThreadPool/blob/master/ThreadPool.h

// comment version, by Joe

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;
    
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};
 
// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    :   stop(false)
{
    for(size_t i = 0;i<threads;++i)   //构造thrread pool的时候会创建线程，线程的执行函数是一个lambda 表达式， 一共起了threads 个线程， 
        workers.emplace_back(
            [this]
            {                         // 在thread的执行函数是一个死循环，并阻塞在wait上，等待一个任务的到达，任务具体怎么执行，是在enqueue时 指定的F(Args ... args)
                for(;;)
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);   // 操作任务队列时， 加锁； 这里必须使用unique_lock(not lock_guard), 因为 wait中 如果条件没有满足， 需要解锁， 只有解锁了enqueue 那边才能加锁并把任务放进队列
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); });  // 等待处理任务
                        if(this->stop && this->tasks.empty())   // 从wait 返回， 说明有任务到达， 返回之后增加了一次判断，什么目的？ notify_one 应该只会唤醒一个线程（析构的时候唤醒所有， 这时stop=true, return）
                            return;
                        task = std::move(this->tasks.front()); // 从任务队列取一个任务
                        this->tasks.pop();
                    }

                    task();  // 执行这个任务
                }
            }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared< std::packaged_task<return_type()> >(     //一个packeged_task 的shard 指针， 执行task() ,实际在执行 F(Args ... args)
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
    std::future<return_type> res = task->get_future();                     // 当task() 执行时有返回值 将返回在 res
    {
        std::unique_lock<std::mutex> lock(queue_mutex);                    // 操作task queue 前要加锁， 离开作用域时自动解锁

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); });                            // 将当前task 放入队列， 放入队列之前包装在lambda表达式中
    }
    condition.notify_one();                                               // 通知线程池中的线程， 任务到达了
    return res;                                                           // 当 执行了 task() 之后， 可以从这个res 中获取返回值， return_val = res.get()， 如果一直没有执行task(), res.get() 应该是阻塞的
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all(); //析构的时候唤醒所有线程
    for(std::thread &worker: workers)
        worker.join();
}

#endif