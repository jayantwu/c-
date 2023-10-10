#include <iostream>
#include <deque>
#include <thread>
#include <mutex>

using namespace std;

std::deque<int> q;
std::mutex mtx;

void push()
{
    while(true) {
        for (auto i = 1; i < 6; i++) {
            {
                //std::scoped_lock lk{mtx};
            {
                //std::lock_guard<std::mutex> lk{mtx};
                cout << "push: before lock" << endl;
                std::scoped_lock lk{mtx};
                q.push_back(i);
            }
            }
            cout << "push succ " << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            //std::this_thread::sleep_for(std::chrono::microseconds(4));
        }
        cout << endl;
        if (q.size() > 100)
            break;
    }
}

void del()
{
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        //std::this_thread::sleep_for(std::chrono::microseconds(20));
        bool last_done = false;
        bool first_done = false;
        cout << "del: before lock" << endl;
        //std::scoped_lock lk{mtx};
        if (q.size() == 0) continue;
        auto start_it = q.begin();
        int first = q.front();
        if (first == 1)
            first_done = true;
        else {
            cout << "it's wrong: " << first << endl;
            for (auto i : q)
                cout << i << " ";
            cout << endl;
            break;
        }
        // find 5
        std::deque<int>::iterator end_it;
        for (auto it = q.begin(); it!=q.end(); it++)
        {
            cout << "cur: " << *it<< " ";
            if (*it == 5) {
                end_it = it;
                last_done = true;
                break;
            }
        }
        cout << endl;

        if (last_done && first_done) {
            {
            //std::scoped_lock lk{mtx};
            {
                //std::lock_guard<std::mutex> lk{mtx};
                //cout << "del: before lock" << endl;
                std::scoped_lock lk{mtx};
                cout << "start: " << *start_it << " end: " << *end_it << endl;
                q.erase(start_it, end_it+1);
            }
            }
            cout << "erase succ" << endl;
        } else {
            cout << "last 5 not ready" << endl;
        }
        cout << "size: " << q.size() << endl;
        for (auto i : q) {
            //cout << "helo" << endl;
            cout << i << " ";
        }
        cout << endl;
        cout << "helo" << endl;
    }
}


int main()
{
    int a = 1;
    thread t1(push);
    thread t2(del);
    t1.join();
    t2.join();
}