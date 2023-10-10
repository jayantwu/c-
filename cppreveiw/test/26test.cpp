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

void push()
{
    while(num--) {
        {
            //scoped_lock lk{mtx};
            q.push_back(1);
        }
        m++;
        cout << "push succ" << endl;
        std::this_thread::sleep_for(std::chrono::microseconds(4000));
        //std::this_thread::sleep_for(std::chrono::microseconds(40));
    }
    cout << "m: " << m << endl;
}

void del()
{
    while(true) {
        if (!q.empty()) {
            //v.push_back(q.front());
            {
                //scoped_lock lk{mtx};
                n++;
                if (q.front() == nullptr) {
                    cout << "null ptr..." << endl;
                    break;
                }
                q.pop_front();
            }
            cout << "pop succ" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            //std::this_thread::sleep_for(std::chrono::microseconds(45)); 
        }
        //if (v.size() >= 1000)
        // if (n >= 10000)
        //     break;

        cout << "n: " << n << endl;
    }
}


int main()
{
    thread t1(push);
    thread t2(del);
    t1.join();
    t2.join();
    //cout << "v.size() " << v.size() << endl;
    // cout << "m=" << m << endl;
    // cout << "n=" << n << endl;
}