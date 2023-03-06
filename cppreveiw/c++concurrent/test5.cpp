#include <iostream>
#include <thread>


using namespace std;

void some_function() {
    cout << "some function...." << endl;
}

void some_other_function() {
    cout << "some other function...." << endl;
}

std::thread f(){
    return std::thread(some_function);
}


std::thread g(){
    std::thread t(some_other_function);
    return t;
}

void f(std::thread t) {
    cout << "f(std::thread t)" << endl;
}

int main() {
    std::thread t1 = f();

    t1.join();

    return 0;

}










