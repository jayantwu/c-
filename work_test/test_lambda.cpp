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




}
