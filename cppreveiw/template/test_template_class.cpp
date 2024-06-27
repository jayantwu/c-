#include <iostream>
#include <memory>

using namespace std;

struct S {
    int a;
    int b;
    friend ostream & operator<<(ostream & os, S &s) {
        cout << "a: "<< s.a << " b:" <<  s.b;
        return os;
    }
};

template<typename T>
class A {
public:
    virtual void set(int n, int m)=0;
    virtual void set(T t)=0;
};

template<typename T>
class B : public A<T> {
public:
    using ss = T;
    virtual void set(int n, int m) {
        ss s = {n, m}; 
        cout << "set B.... " << s << endl; 
    }
    virtual void set(T t) {
        cout << "set B.... " << t << endl; 
    }
};


class C : public B<S> {
public:
    virtual void set(int n, int m) {
        ss s = {n, m}; 
        cout << "set C.... " << s << endl; 
    }
    virtual void set(B<S>::ss t) {
        cout << "set C.... " << t << endl; 
    }
};

int main()
{
    //B<S>::ss s = {.a = 33, .b=1};
    auto B_ptr = make_shared<B<S>>();

    B_ptr->set(3, 5);

    auto B_ptr_i = dynamic_pointer_cast<A<S>>(B_ptr);

    B_ptr_i->set(3, 5);

    B_ptr_i->set({33, 55});

    auto C_ptr = make_shared<C>();

    C_ptr->set(3, 5);

    auto C_ptr_i = dynamic_pointer_cast<A<S>>(C_ptr);

    C_ptr_i->set(4, 5);

    return 0;
}


/*
set B.... a: 3 b:5
set B.... a: 3 b:5
set B.... a: 33 b:55
set C.... a: 3 b:5
set C.... a: 4 b:5
*/