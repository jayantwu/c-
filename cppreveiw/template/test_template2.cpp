#include <iostream>
#include <string>
using namespace std;



class A {
public:
    A ()
    {
        cout << "A()" << endl;
    }
};

class B {
public:
    B ()
    {
        cout << "B()" << endl;
    }
};


template<typename T>
class Base {
public:
    Base(){
        cout << "Base()" << endl;
    }
    virtual ~Base()=default;
    //T t;

};

template<typename T>
class Drive : public Base<T> {
public:
    Drive() : Base<T>() {
        cout << "Drive()" << endl;
    }
};


int main()
{
    Drive<A> d;
    Drive<B> d2;
}