#include "item22.h"

struct A::Impl {
    int a; 
    int b;
};

A::A() : pImpl(make_unique<Impl>())
{

}

unique_ptr<A::Impl> & A::getptr()
{
    return pImpl;
}
//A::~A()=default;




int main()
{
    A a;
    a.getptr()->a = 1;
    a.getptr()->b = 2;

    
    return 0;

}


