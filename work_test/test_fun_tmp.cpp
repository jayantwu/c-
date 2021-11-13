#include<iostream>
#include<string>
#include <typeinfo>
#include <typeindex>

using namespace std;
template<typename T>
T fun1(T & a)
{
    T b;
    cout << a << endl;
    return b;
}
template<typename T>
T* fun2()
{
    T* mem = new T();
    return mem;
}


template<typename T1, typename T2>
void fun3(T1 x, T2 y)
{
    decltype(x+y) z = x + y;

}

template<typename T1, typename T2>
auto fun4(T1 x, T2 y) -> decltype(x+y)  //trailing return type
{
    return x + y;
}



int main()
{
    int a = 1;
    fun1(a);
    int *b = fun2<int>();
    *b = 5;
    cout << b << ": " << *b << endl;
    delete(b);

    fun3(3, 3.3);

    auto z = fun4(3, 3.4);
    cout << z << endl;


}