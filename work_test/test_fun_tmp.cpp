#include<iostream>
#include<string>
#include <typeinfo>
#include <typeindex>

using namespace std;
template<typename T>
T test1(T & a)
{
    T b;
    cout << a << endl;
    return b;
}



int main()
{
    int a = 1;
    test1(a);
}