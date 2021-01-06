//约束模板友元函数 
#include <iostream>
using namespace std;

// declare template function, T(function) = class<T>
template <class T> class MyNumber;
template <class T> void PrintNumber(MyNumber<T> &number);

template <class T>
class MyNumber
{
private:
    T m_number;

public:
    MyNumber(T number) : m_number(number) {}
    ~MyNumber() {}

public:
    // declare friend function
    friend void PrintNumber<>(MyNumber<T> &number);  //friend void PrintNumber<>(MyNumber<T> &number); 
};

// function definition
template <class T>
void PrintNumber(MyNumber<T> &number)
{
    cout << "The Number is : " << number.m_number << endl;
}

int main()
{
    MyNumber<int>   n0(1);
    MyNumber<float> n1(2.3);
    PrintNumber(n0);    //传入的参数是 MyNumber<int>类型的对象 ，因而上面的 PrintNumber友元函数声名的参数类型是 MyNumber<T> 
    PrintNumber(n1);

    return 1;
}