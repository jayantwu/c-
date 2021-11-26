#include <iostream>
#include <functional>   //std::cout
using namespace std;
using namespace std::placeholders;    // adds visibility of _1, _2, _3,...

class Test
{
public:
    int i = 0;

    void func(int x, int y)
    {
        cout << x << " " << y << endl;
    }
};

void fun1(int x)
{
    cout << x << endl;
}

int main()
{
    Test obj; //创建对象

    function<void(int, int)> f1 = bind(&Test::func, &obj, _1, _2);
    f1(1, 2);   //输出：1 2

    function< int &()> f2 = bind(&Test::i, &obj);
    f2() = 123;  //？？啥意思？
    cout << obj.i << endl;//结果为 123

    auto f3 = bind(&Test::func, &obj, _2, 4);
    f3(5, 6);   // out put 6 4  , 5 is unused, 必须提供两个参数
    //f3(4);   //error
    auto f4 = bind(&Test::func, &obj, _2, _1);
    f4(4, 5);  // 5 4
    //f4(4);  //compile error
    auto f5 = bind(&Test::func, &obj, 5, _1);
    f5(4);  //5 4

    auto f6 = bind(&fun1, _1);
    f6(5,6); // it's ok   5
    f6(5); // 5

    return 0;
}
