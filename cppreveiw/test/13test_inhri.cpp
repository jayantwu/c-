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
#if 0
        virtual void setfun()
        {
            fun1();
        }
#endif
        static void fun1()
        {
            cout << "base static fun1" << endl;
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
#if 0
        virtual void setfun()
        {
            fun1();
        }
#endif
        static void fun1()
        {
            cout << "A static fun1" << endl;
            //check();
        }

        void check()
        {
            cout << "A check()" << endl;
        }
};


int main()
{
    Base* obj = new A();
    obj->pprint();
    delete obj;



}

/*
A class setup
*/
