// g++ -std=c++11 test12.cpp -lpthread
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <queue>
#include <string>

constexpr int MAX_PRODUCT_NUM = 1000;

template<typename T>
class threadsafe_queue
{
    private:
        std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;

    public:
        void push(T new_value)
        {
            std::lock_guard<std::mutex> lk(mut);
            data_queue.push(new_value);
            data_cond.notify_one();
        }

        void wait_and_pop(T& value)
        {
            std::unique_lock<std::mutex> lk(mut);
            data_cond.wait(lk, [this] { return !data_queue.empty();});
            value = data_queue.front();
            data_queue.pop();
        }
};

threadsafe_queue<std::string> data_queue;

static int prepared_product_num = 0;
static int process_product_num = 0;
std::string prepare_data()
{
    return "product " + std::to_string(prepared_product_num++);
}

bool more_data_to_prepare()
{
    if (prepared_product_num > MAX_PRODUCT_NUM)
        return false;
    return true;
}

void process(std::string &data)
{
    data = "processed " + data;
}


bool is_last_product()
{
    return process_product_num > MAX_PRODUCT_NUM;
}

void data_prepare()
{
    while(more_data_to_prepare())
    {
        std::string const data = prepare_data();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << data << std::endl;
        data_queue.push(data);
    }
}

void data_process()
{
    while(true)
    {
        std::string data;
        data_queue.wait_and_pop(data);
        process(data);
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        process_product_num++;
        std::cout << data << std::endl;
        if (is_last_product())
            break;
    }
}
 

 
int main()
{
    std::thread t1 {data_prepare};
    std::thread t2 {data_process};

    t1.join();
    t2.join();

    return 0;
}