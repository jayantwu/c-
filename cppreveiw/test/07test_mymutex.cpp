#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>

using namespace std;
namespace test {
class Mutex 
{
public:
    Mutex(Mutex&)=delete;
    void operator=(const Mutex&)=delete;
    
    Mutex()
    {
        if (0 != pthread_mutex_init(&mutex, NULL))
           cout <<  "mutex init failed" << endl;
    }

    ~Mutex()
    {
        if (0 != pthread_mutex_destroy(&mutex))
        {
            cout <<  "mutex destroy failed" << endl;
        }
    }

    void lock()
    {
        if (0 != pthread_mutex_lock(&mutex))
        {
            cout <<  "mutex lock failed" << endl;
        }    
    }

    void unlock()
    {
        if (0 != pthread_mutex_unlock(&mutex))
        {
            cout <<  "mutex unlock failed" << endl;
        }   
    }
private:
    pthread_mutex_t mutex;
};


class Mutexlock 
{
public:
    explicit Mutexlock(Mutex* mu) : _mu(mu)
    {
        _mu->lock();
    }

    ~Mutexlock()
    {
        _mu->unlock();
    }
    Mutexlock(Mutexlock&)=delete;
    void operator=(const Mutexlock&)=delete;
private:
    Mutex *const _mu;
};


int k = 0;
Mutex mutex;

void fun1()
{ 
    {
        Mutexlock Lock(&mutex);
        //cout << "fun1" << endl;
        k++;
    }
    //sleep(1);
}


} // end of namespace test

int main()
{
    using namespace test;
    vector<thread> v;
    for (int i = 0; i < 10000; i++)
        v.emplace_back(&fun1);

    for (auto& t : v)
    {
        t.join();
    }

    cout << k << endl;
    return 0;

}

