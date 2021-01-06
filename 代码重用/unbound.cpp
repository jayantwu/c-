//非约束模板友元 
#include <iostream>
using namespace std;

template <class T>
class MyNumber
{
private:
    T m_number;

public:
    MyNumber(T number) : m_number(number) {}
    ~MyNumber() {}

public:
    template <class D>
    friend void PrintNumber(D &number);
};

template <class T>
void PrintNumber(T &number)
{
    cout << "The Number is : " << number.m_number << endl;
}

int main()
{
    MyNumber<int>   n0(1);
    MyNumber<float> n1(2.3);
    PrintNumber(n0);
    PrintNumber(n1);

    return 1;
}