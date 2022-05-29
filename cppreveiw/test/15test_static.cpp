#include <iostream>


using namespace std;

class Base 
{
    public:
        virtual void setup(){
            cout << "base class setup" << endl;
        }
        virtual void pprint()
        {
            setup();
            //setfun();
            fun1();
        }

        static void fun1()
        {
            cout << "base static fun1" << endl;
        }
        virtual void check()
        {
            cout << "Base check()" << endl;
        }
};

class A : public Base {
    public:
        virtual void setup() {
            cout << "A class setup" << endl;
        }
        virtual void pprint()
        {
            setup();
            fun1();
            
        }
        static void fun1()
        {
            cout << "A static fun1" << endl;
        }

        void check()
        {
            Base::fun1();
            cout << "A check()" << endl;
        }
};


int main()
{
    Base* obj = new A();
    obj->check();
    delete obj;



}

/*
A class setup
*/
