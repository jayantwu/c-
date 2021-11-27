#include <iostream>
#include <string>
using namespace std;
class A {
public:
    virtual void show(string s = "hi")=0;
};

class B : public A {
public:
    void show(string s = "jiayang") {
        cout << s << endl;
    }
};


int main()
{
    B b;
    A * ptra = &b;  // ptra的动态类型是B
    b.show();   // jiayang
    ptra->show();  // hi   // 使用了基类的缺省值

}