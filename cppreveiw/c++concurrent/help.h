#pragma once
#include <exception>

using namespace std;

struct MyException : public exception 
{
    const char* what() const throw () {
        return "My C++ Exception";
    }
};

