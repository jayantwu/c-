#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class A
{
public:
    void f0()
    {
        cout << "f0" << endl;
    }
    void f1()
    {
        cout << "f1" << endl;
    }
    void f2()
    {   
        cout << "f2" << endl;
    }
};


class B
{
public:
    void f(int n)
    {
        //vector<void (A::*)()> v_f1 {&A::f0, &A::f1, &A::f2};
        //(obj_a.*v_f1[n])();

        
        vector< function<void()> > v_f2 {
                                         [this]{obj_a.f0();},
                                         [this]{obj_a.f1();},
                                         [this]{obj_a.f2();}
                                        };
        v_f2[n]();
        

        /*
        if (n == 0)
            obj_a.f0();
        else if (n == 1)
            obj_a.f1();
        else if (n == 2)    
            obj_a.f2();
        */   


           
    }
private:
    A obj_a;
};


int main()
{
    B b;
    b.f(2);
    
}