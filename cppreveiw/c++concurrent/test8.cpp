#include <iostream>
#include <thread>
#include "help.h"
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;

mutex g_mutex;
list<int> g_list;

void add_to_list(int n)
{
    lock_guard<mutex> guard(g_mutex);
    g_list.push_back(n);
}

bool list_contains(int value_to_find)
{
    return (std::find(g_list.begin(), g_list.end(), value_to_find)) != g_list.end();
}


void f1()
{
    cout << "f1...." << endl;
    for (auto i = 0; i < 50; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        add_to_list(i);
    }
}
void f2()
{
    cout << "f2...." << endl;
    for (auto i = 50; i < 100; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        add_to_list(i);
    }
}

int main() {
    

    thread t1(f1);

    thread t2(f2);



    t1.join();
    t2.join();

    for (auto &i : g_list)
        cout << i << endl;
    cout << "nums: "  << g_list.size() << endl;
    return 0;

}










