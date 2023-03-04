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
            this_thread::sleep_for(std::chrono::microseconds(2000));
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


int main() {

    int a = 0;
    backgroud_task f(a);
    thread my_thread(f);

    try
    {
       do_my_current_task();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        my_thread.join();  // test: after call join(), throw excepton to end current thread, backgroud task can run normally
        throw;
    }
    //do_my_current_task();

    my_thread.join();

    return 0;
}