// compile with "g++ -std=c++11 -fno-elide-constructors test_rval.cpp"
#include<iostream>
using namespace std;


class HasPtrMem
{
public:
    HasPtrMem():d(new int (0)){cout << "constructor()\n";}
    HasPtrMem(int n):d(new int(n)){cout << "constructor(n)\n";}
    HasPtrMem(HasPtrMem& h):d(new int(*h.d)){cout << "copy constructor\n";} 
    HasPtrMem(HasPtrMem&& h):d(h.d)    //get the pointer, move constructor
    {
        h.d = nullptr;    
        cout << "move constructor\n";
    } 
    ~HasPtrMem()
    {
        
        delete d;
        cout << "destructor\n";
    }
    int *d;
};


HasPtrMem gettemp()
{
    HasPtrMem h;   // constructor()
    return h;
}


int main()
{
#if 0
    HasPtrMem a(2);
    HasPtrMem b(a);
    cout << *a.d << endl;
    cout << *b.d << endl;
#endif
#if 0
    HasPtrMem c = gettemp();
    /*
    constructor()
    move constructor
    destructor
    move constructor
    destructor
    destructor
    */
#endif

    int b = 3;
    int && c = b+2;   //rval must conbine to rval
    cout << c << endl;

    const HasPtrMem &a = gettemp();    //constant lval  reference can conbine to right val

}