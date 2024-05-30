#include <string>
#include <iostream>
using namespace std;

class A_i 
{
    public:
        virtual string name() = 0;
};


class A : public A_i 
{
    public:
        A() : m_name("I'm A") {}
        virtual string name() {
            return m_name;
        }
    
    private:
        string m_name;
};


class B : public A
{
    public:
        B() : m_name("I'm B") {}
        virtual string name() {
            return m_name;
        }
    
    private:
        string m_name;
};

int main()
{
    // A a;

    // cout << a.name() << endl;

    // A_i * a_i = dynamic_cast<A_i*>(&a);
    // cout << a_i->name() << endl; 
    B b;
    cout << b.name() << endl;
    cout << dynamic_cast<A*>(&b)->name() << endl;


}