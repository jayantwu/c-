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
        A(string name) : m_name(name) {}
        virtual string name() {
            return m_name;
        }
    
    private:
        string m_name;
};


int main()
{
    A a("Joe");

    cout << a.name() << endl;

    A_i * a_i = dynamic_cast<A_i*>(&a);
    cout << a_i->name() << endl; 
}