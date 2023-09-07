#include <iostream>


// check input a is left value or right value
template<typename T>
void process(T && a)
{
    std::cout << "is right value" << std::endl;
}

template<typename T>
void process(T & a)
{
    std::cout << "is left value" << std::endl;
}

template<typename T>
void check_lr(T&& t)
{
    process<T>(std::forward<T>(t));
}