#include <iostream>
#include <thread>
using namespace std;

void hello() {
    cout << "hello world" << endl;
}


void do_something() {
    cout << "do somethig first" << endl;
}

void do_something_else() {
    cout << "do something second" << endl;
}

class backgroud_task {
    public:
        void operator()() {
            do_something();
            do_something_else();
        }
};



int main() {

    thread t(hello);  // pass a function

    backgroud_task f;  // functor
    thread my_thread(f);  // pass a functor

    thread my_thread2([](){   //lambda expression
        do_something();
        do_something_else();  
    });

    t.join();
    my_thread.join();
    my_thread2.join();


}