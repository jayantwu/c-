#include<iostream>
#include<mutex>
#include<thread>
#include<unistd.h>

using namespace std;

int k = 0;
int g = 0;

mutex g_mutex;

void fun1()
{ 
    while (k < 10)
    {
        g_mutex.lock();
        cout << "fun1" << endl;
        k++;
        g_mutex.unlock();
        sleep(1);
        
    } 
}

void fun2()
{
    while (k < 10)
    {
        g_mutex.lock();
        cout << "fun2" << endl;
        k++; 
        g_mutex.unlock();
        sleep(1);
        
    } 
}

void fun3()
{
    while (g < 100)   // has a issue, these two threads use conditon variable is well
    {
        {  //注意作用域, IO需要单独加所=锁
            lock_guard<mutex> {g_mutex};
            cout << __func__ 
                 << ": g is " 
                 << g 
                 << endl;
        }
        {
            lock_guard<mutex> lock(g_mutex);
            g++;
        }
        usleep(200);
        
    } 
}

void fun4()
{
    while (g < 100)
    {
        {
            lock_guard<mutex> {g_mutex};
            cout << __func__ 
                 << ": g is " 
                 << g 
                 << endl;
        }
        {
            lock_guard<mutex> lock(g_mutex);
            g++; 
        }
        usleep(200);
    } 
}

int main()
{
    //thread t1(fun1);
    //thread t2(fun2);
    thread t3(fun3);  
    thread t4(fun4);


    //t1.join();
    //t2.join();
    t3.join();
    t4.join();

    return 0;
}