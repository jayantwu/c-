#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;


std::mutex mtx;



class A {
public:
    int a;
    A() {
        cout << "ctor..."<< endl;
    }
};

std::deque<unique_ptr<A>> q;

void create_a() {
    while(true) {
        auto uptr = unique_ptr<A>{new A()};
        uptr->a = 1;
        q.push_back(std::move(uptr));
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void use_a() {
    while(true) {
        if (!q.empty()) {
            auto &uptr = q.front();
            try {
                cout << "a: " << uptr->a << endl;
            }
            catch (const exception &e) {
                cout << e.what() << endl;
                break;
            }
            q.pop_front();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

int main() {
    
    thread t1(use_a);
    thread t2(create_a);
    t1.join();
    t2.join();
    

}