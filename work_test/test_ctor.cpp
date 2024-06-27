#include <iostream>


using namespace std;

struct A {
    int _a;
    int _b;
    A() : _a(0), _b(0) {
        _a = 10;
    }
};

int main()
{
    A a;
    cout << a._a << endl;
    cout << a._b << endl;
}