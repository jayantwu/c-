#include <iostream>
using namespace std;

class testA
{
    public:
        int a;
        double b;
    public:
        testA(int x, double y): a(x), b(y)
        {

        }

        testA()=default;

        testA(testA &)=default;   //it's differenct from testA(testA &){}

        ~testA(){cout << "destructor" << endl;}
};

int main()
{
    testA p;
    testA point1(2, 3.2);
    testA point2(point1);
    cout << point2.a << " " << point2.b << endl; // 2 3.2
    cout << p.a << " " << p.b << endl; //0 0
}