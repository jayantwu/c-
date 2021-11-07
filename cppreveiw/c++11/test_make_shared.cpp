#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

class testA
{
    private:
        int x;
        int y;
    public:
        testA()=default;
        testA(int a, int b): x(a), y(b)
        {
            cout << "constructor..." << endl;
        }
        void show()
        {
            cout << x << setfill(' ') << setw(2) << y << endl; 
        }
};


int main()
{
    shared_ptr<testA> sA = make_shared<testA>(5, 6);    //will call testA(int a, int b)
    sA->show();
    auto sB = sA;
    sB->show();
    unique_ptr<testA> uA = make_unique<testA>(10, 9);
    uA->show();
    auto uB = move(uA);
    uB->show();
    //uA->show();    //running error  uA is a nullptr



}