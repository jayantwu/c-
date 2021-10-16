#include<iostream>
#include<unistd.h>
using namespace std;

class testClassA
{
    private:
        int a, b;
        int *buff;

    public:
        testClassA(int x, int y);
        //testClassA();
        ~testClassA();
        int geta(){return a;}
        int getb(){return b;}
        virtual void show();
};




void testClassA::show()
{
    cout << "a = " << a << " b = " << b << endl;
}

testClassA::testClassA(int x, int y):a(x), b(y)
{
    buff = new int[10];
    cout << "call testClassA(int x, int y)\n";
}

testClassA::~testClassA()
{
    delete [] buff;
    cout << "call ~testClassA()" << endl;
}


class testClassB: public testClassA
{
    private:
        int c;

    public:
        testClassB(int x, int y, int z):testClassA(x, y), c(z)
        {
            cout << "call testClassB(int x, int y, int z)\n";
        }
        ~testClassB()
        {
            cout << "call ~testClassB()" << endl;
        }
        void show();



};

void testClassB::show()
{
    cout << "a = " << geta() << " b = " << getb() << " c = " << c << endl;
}


void test1(testClassA &obj_1)   //here need to pass by reference, otherwise the buff will be freed twice
{

}

//must return obj not ref
testClassA  test2(testClassA & obj_2)
{
    testClassA obj_tmp(1,2);
    return obj_tmp;  //tmp obj can't return by reference, compiler may throw an exception

}




int main()
{
#if 0
    testClassA a(2, 3);
    //a.show();
    test1(a);
    
    sleep(5);

    test2(a);
#endif

#if 1
    testClassA a(2, 3);
    testClassB b(1,2,3);
    //b.show();
    testClassA * ref_class[2] = {&a, &b};   //no reference array, must be pointer array
    for (int i = 0; i < 2; i++)
        ref_class[i]->show();
 #endif
    return 0;
}





