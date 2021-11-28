#include <iostream>
#include <memory>
#include <vector>
using namespace std;


int main()
{
    
    int ret;
    auto fun1 = [](int a = 0){
        cout << "hello world!" << endl;
        cout << a << endl;
    };    //semicolon is needed

    fun1();
    fun1(5);  //

    int b = 5;
    auto fun2 = [b](int a) {     //capture b
        cout << "a + b = " << a + b << endl;
    };

    fun2(11);


    auto fun3 = [b](int a)->int {return a + b;};    //return type is int
    ret = fun3(12);
    cout << ret << endl;


    int y = [](int x, int y)->int {
        return x + y;
    }(1, 2);

    cout << "y= " << y << endl;

    int a = 6;
    auto f1 = [a](int x)mutable->int  {    // use mutable, can cchange the capture, defaul is const
        a = a + x;
        return a;
    };

    auto f2 = [&a](int x) -> int {   // use reference, can change the capture 
        a = a + x;  
        return a;
    };

    cout << f1(3) << endl;
    cout << f2(3) << endl;





}
