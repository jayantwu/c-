#include <iostream>

using namespace std;

double divide(int a, int b) {
    if (b == 0)
        throw "dividor can not be zero";
    return double(a) / b;
}

void fun()  
{
    divide(5, 0);
    cout << "sss" << endl;
}


class bad1 {
public:
    bad1(int x):v(x) {}
    virtual void msg() 
    {
        cout << "this is bad 1" << endl; 
    }
private:
    int v;
};


class bad2 : public bad1 {
public:
    bad2(int x) : bad1(x) {}
    virtual void msg()
    {
        cout << "this is bad 2" << endl; 
    }
};  

class bad3 : public bad2 {
public:
    bad3(int x): bad2(x) {}
    virtual void msg()
    {
        cout << "this is bad 3" << endl; 
    }
};  


int test_fun(int x)
{
    if (x > 0)
        throw bad1(x);
    if (x == 0)
        throw bad2(x);
    if (x < 0)
        throw bad3(x);
    return 0;
}

int main()
{
    try 
    {
        fun();  //栈解退， fun调用了一个可能抛出异常的函数
    }
    catch (const char*s)
    {
        cout << s << endl;
    }


    for (int i = -1; i < 2; i++) 
    {
        try 
        {
            test_fun(i);
        }
        catch (bad3 & e)  //只能捕捉bad3
        {
            e.msg();
            continue;
        }
        catch (bad2 & e)  //可以捕捉bad2， bad3
        {
            e.msg();
            continue;
        }
        catch (bad1 & e)   // 使用引用，可以指向子类异常, 可以捕捉到bad1 bad2 bad3
        {
            e.msg();
            continue;
        }
        catch (...)
        {
            cout << " other exception" << endl;
        }
    }

    return 0;

}
