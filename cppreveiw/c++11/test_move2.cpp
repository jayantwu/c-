//g++ -std=c++11 -fno-elide-constructors test_move2.cpp
#include<utility>
#include<iostream>
using namespace std;

class HugeMem
{
    public:
        HugeMem(int size): sz(size > 0 ? size : 1){
            c = new int [sz];
            cout << "HugeMem: constructor" << endl;
        }
        ~HugeMem(){
            delete [] c;
            cout << "HugeMem: destructor" << endl;
        }
        HugeMem(HugeMem&& hm): sz(hm.sz), c(hm.c){
            hm.c = nullptr;
            cout << "HugeMem: move constructor" << endl;
        }
        int *c;
        int sz;
};


class Moveable{
    public:
        Moveable(): i(new int(3)), h(1024){}
        ~Moveable() {
            delete i;
            cout << "Moveable: destructor" << endl;    
        }
        Moveable(Moveable && m): i(m.i), h(move(m.h))  //mandatory transfer to rval,
        {
            m.i = nullptr;
            cout << "Moveable: move constructor" << endl;
        }
        int * i;
        HugeMem h;
};

Moveable gettemp()
{
    Moveable tmp = Moveable();  //call move ctor
    return tmp;
}

int main()
{
    Moveable a(gettemp());
}