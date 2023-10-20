#include "../inc/app.h"
#include <iostream>

using namespace std;

void App::run() {
    cout << "running" << endl;
}

void App::show() {
    cout << "hello world" << endl;
}

void App::add(int a, int b) {
    cout << "sum is " << a + b << endl;
}

