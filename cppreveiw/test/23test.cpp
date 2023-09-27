#include <iostream>

using namespace std;
class B {
    public:
    B() { cout << "B()" << endl; }
    void print() {
        cout << "hello world" << endl;
    }
};


template<typename T>
class A {
    public:
        A()=default;
        using record_t = T;
        //record_t m_member;
};

int main()
{
    A<B> a;
    A<B>::record_t b;
    b.print();
}

