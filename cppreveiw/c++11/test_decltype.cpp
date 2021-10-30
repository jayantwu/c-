#include<iostream>

int main()
{
    int a = 10;
    decltype(a) b;  // the type of b is int, same with a
    b = 10;
}