#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base 
{
    public:
        virtual void setup(){
            cout << "base class setup" << endl;
            cout << "v size " << v.size() << endl;
        }
    vector<int> v;

};

class A : public Base {
    public:
        virtual void setup() {
            cout << "A class setup" << endl;
            v.emplace_back(1);
            cout << "size " << v.size() << endl;
        }
};


int main()
{
    Base* obj = new A();
    obj->setup();
    cout << obj->v.size() << endl;
    delete obj;



}

/*
A class setup
*/
