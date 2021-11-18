#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <iomanip>
#include <string>
using namespace std;
class Point
{
    private:
        int a;
        int b;

    public:
        Point(int x, int y): a(x), b(y){}
        Point()=default;
        ~Point()=default;
        template<typename T>
        void get_and_show(const T& x);

};

template<typename T>
void Point::get_and_show(const T& x)
{
    type_index idx = type_index(typeid(T));
    if (idx == type_index(typeid(int)))
        cout << "this is a int num" << setw(10) << setfill('-') << x << endl;
    else if (idx == type_index(typeid(double)))
        cout << "this is a double num" << setw(10) << setfill('-') << x << endl;
    else if (idx == type_index(typeid(string)))
        cout << "this is a string" << setw(10) << setfill('-') << x << endl;
    else
        cout << "can't identify " << endl;
}


int main()
{
    Point p1(1,2);
    p1.get_and_show(5);
    p1.get_and_show(1.2);
    p1.get_and_show(string("hello"));
    p1.get_and_show<string>("world"); // explict 


    return 0;
}

