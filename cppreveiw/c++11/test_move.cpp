//
#include<utility>
#include<iostream>
using namespace std;


class Movable
{
    public:
        Movable():i(new int(3)){}
        ~Movable(){delete i;}
        Movable(const Movable& m): i(new int(*m.i)){}
        Movable(Movable&& m):i(m.i)
        {
            m.i = nullptr;
        }
        int * i;

};







int main()
{
    Movable a;
    //Movable c(move(a)); // call move construtor, make a.i=nullptr
    cout << *a.i << endl;    //running error!

}