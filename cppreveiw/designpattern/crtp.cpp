#include <iostream>

using namespace std;

template <typename T>
class Base
{
public:
    void dosomthing()
    {
        T& derived = static_cast<T&>(*this);
        derived.show();
    }
};

class Derived1 : public Base<Derived1> 
{
public:
    void show() {
        cout << "hello world~ i'm derived1." <<  endl;
    }
};

class Derived2 : public Base<Derived2> 
{
public:
    void show() {
        cout << "hello world~ i'm derived2." <<  endl;
    }
};

template<typename T>
void processderive(Base<T> *b) {
    b->dosomthing();
}

int main()
{
    Base<Derived1> * d1 = new Derived1();
    d1->dosomthing();
    Derived2 d2;
    d2.dosomthing();
    return 0;
}