#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::weak_ptr;
using std::vector;
using std::make_unique;



class A {
private:
    struct Impl;
    unique_ptr<Impl> pImpl;

public:
    A();
    //~A();
    unique_ptr<Impl>& getptr();

};