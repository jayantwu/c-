#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

constexpr int NUM = 10000;

std::deque<int> q;
std::mutex mtx;
int num = NUM;
std::vector<int> v;
int n = 0;
int m = 0;
bool stop = false;

void push()
{
    while(num--) {
        {
            //scoped_lock lk{mtx};
            q.push_back(m);
        }
        printf("push succ: %d\n", m);
        //cout << "push succ: " << m << endl;
        m++;
        
        std::this_thread::sleep_for(std::chrono::microseconds(4000));
        //std::this_thread::sleep_for(std::chrono::microseconds(40));
    }
    cout << "m: " << m << endl;
}

void pop()
{
    while(true) {
        if (!q.empty()) {
            cout << "q.size() " << q.size() << endl;
            //v.push_back(q.front());
            //cout << "front: " <<  q.front() << endl;
            printf("front: %d\n", q.front());
            {
                //scoped_lock lk{mtx};
                n++;
                q.pop_front();
            }
            //cout << "pop succ" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(4));
            //std::this_thread::sleep_for(std::chrono::microseconds(45)); 
        }

        cout << "n: " << n << endl;
        if (stop && q.empty()) 
            break;        
    }
}


int main()
{
    thread t1(push);
    thread t2(pop);
    t1.join();
    if (!t1.joinable())
        stop = true;
    t2.join();

    //cout << "v.size() " << v.size() << endl;
    // cout << "m=" << m << endl;
    // cout << "n=" << n << endl;
}