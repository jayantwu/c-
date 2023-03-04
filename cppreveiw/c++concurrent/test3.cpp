#include <iostream>
#include <thread>
#include <exception>
#include "help.h"

using namespace std;



void do_something(int a) {
    cout << "do somethig first...."  << a << endl;
    for (auto i = 0; i < 5; i++) {
        cout << "task A" << endl;
        this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void do_something_else(int a) {
    cout << "do something second...." << a << endl;
    for (auto i = 0; i < 5; i++) {
        cout << "task B" << endl;
        this_thread::sleep_for(std::chrono::microseconds(100));
    }
}



class backgroud_task {
    public:
        int &a;
        backgroud_task(int & a_): a(a_){
            cout << "backgroud constructor..." << endl;
        }
        void operator()() {
            this_thread::sleep_for(std::chrono::microseconds(500));
            do_something(a);
            do_something_else(a);
        }

        ~backgroud_task() {
            cout << "backgroud task destructor...." << endl;
        }
};

void do_my_current_task() {

    cout << "do_current_task...." << endl;
    for (auto i = 0; i < 10; i++) {
        cout << "current task " << i << endl;
        this_thread::sleep_for(std::chrono::microseconds(100));
    }

    throw MyException();
}


class thread_guard {
        thread & t;
    public:
        explicit thread_guard(thread & t_): t(t_) {

        }

        ~thread_guard() {
            cout << __func__ << " destructor.." << endl;
            if (t.joinable())
                t.join();
        }
};

void fun() {  // this function must in try block
    int a = 0;
    backgroud_task f(a);
    thread my_thread(f);
    thread_guard g(my_thread);
    do_my_current_task(); // if this fun raise exception, ~thread_guard() will first execute
}

int main() {

    try
    {
        fun();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}