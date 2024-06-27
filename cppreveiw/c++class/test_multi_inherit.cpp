#include <iostream>

using namespace std;

class A {
    public:
        virtual void set()=0;
};



class B {
    public:
        virtual void show()=0;
};


class C : public A , public B {
    public:
        virtual void set() override {
            cout << "set: ....." << endl;
        }
        virtual void show() override {
            cout << "show.... " << endl;
        }
};


int main()
{
    C c;

    c.set();
    c.show();

    auto c_ptr = make_shared<C>();

    shared_ptr<A> a_ptr = c_ptr;

    a_ptr->set();
    //a_ptr->show();
    dynamic_pointer_cast<B>(a_ptr)->show();
    
    return 0;
}