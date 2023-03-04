#include <string>
#include <iostream>
#include <exception>

using namespace std;

///// test exception
struct MyException : public exception 
{
    const char* what() const throw () {
        return "C++ Exception";
    }
};



int main()
{

    try
    {
        throw MyException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}



