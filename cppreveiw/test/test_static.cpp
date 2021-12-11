#include <iostream>




class A {
public:
    void method();

};

class B {
public:
    static int method() {
        std::cout << "method of b" << std::endl;
        return 0;
    }
};

class C {
    static C * ptr_c;
    C(){}
public:
    static C* getInstance()
    {
        if (ptr_c == nullptr)
            ptr_c = new C();
        return ptr_c;
    }
    void show()
    {
        std::cout << "this is class C" << std::endl;
    }
};
C * C::ptr_c;

void A::method()
{
    B::method();
}



class D {
    D(){}
public:
    static D* getInstance()
    {
        static D d;
        return &d;
    }
    void show()
    {
        std::cout << "this is class D" << std::endl;
    }
};


int main()
{
    class A a;
    a.method();

    C* ptrc = C::getInstance();
    ptrc->show();

    D* ptrd = D::getInstance();
    ptrd->show();
}


