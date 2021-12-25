#include <iostream>
#include <vector>
#include <functional>
#include<variant>
using namespace std;

class Base 
{
public:
    virtual ~Base()=default;

};

class D1 : public Base
{
public:
    void show()
    {  
        cout << "D1::show()" << endl;
    }

};

class D2 : public Base
{
public:
    void show()
    {  
        cout << "D2::show()" << endl;
    }

};

class D3 : public Base
{
public:
    void show()
    {  
        cout << "D3::show()" << endl;
    }
};

class A
{
public:
    D1* f0()
    {
        cout << "f0" << endl;
        return &d1;
    }
    D2* f1()
    {
        cout << "f1" << endl;
        return &d2;
    }
    D3* f2()
    {   
        cout << "f2" << endl;
        return &d3;

    }

private:
    D1 d1;
    D2 d2;
    D3 d3;
};


class B
{
public:
    void f(int n)
    {
        //vector<void (A::*)()> v_f1 {&A::f0, &A::f1, &A::f2};
        //(obj_a.*v_f1[n])();
        /*
        using var_t = std::variant<function<D1*()>, function<D2*()>, function<D3*()>>;
        
        vector< var_t > v_f2 {
                                [this]{obj_a.f0();},
                                [this]{obj_a.f1();},
                                [this]{obj_a.f2();}
                             };
        //std::visit([this]()->decltype(v_f2[n]){return v_f2[n];}, v_f2[n]) ();
       
        */
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
/*
    shared_ptr<Base> ptrb;
    vector<shared_ptr<Base>> v_b { make_shared<D1>(), make_shared<D2>(), make_shared<D3>() };
    std::dynamic_pointer_cast<D1>(v_b[0])->show();
    
    void f1();
    int f2();
    char f3();

    using var_t = std::variant<void(*)(), int(*)(), char(*)()>;

    vector<var_t> v {f1, f2, f3};

    v[0]();

*/

  
    


}