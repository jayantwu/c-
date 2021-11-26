#include <iostream>
using namespace std;

constexpr int fun1(int x)    // in c++14 can use more than one line code
{
    if (x > 0)     // it will be compiled error in c++11
        return x;
    return 0;
}

int main()
{
    fun1(1);
}