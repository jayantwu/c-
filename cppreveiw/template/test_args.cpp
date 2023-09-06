#include <iostream>
#include <vector>

using namespace std;

// 递归终止函数
void print()
{
    cout << "empty" << endl;
}

// template<typename T>
// void print(T t)
// {
//     cout << t << endl;
// }

template<typename T, typename... Args>
void print(T head, Args... rest)
{
    cout << "parameter " << head << endl;
    print(rest...);
}




// 求和 举例
template<typename T>
T sum(T t)
{
    return t;
}

template<typename T, typename... Types>
T sum(T first, Types ... rest)
{
    return first + sum<T>(rest...); //sum<T>  实例化
}



template<typename T, typename U>
T fun(U u)
{   
    return u + 1.1;
}


int main()
{
    print(1,2,3,4);
    /*
    print(1,2,3,4)   // void print<int, int, int, int>(int head, int rest, int rest, int rest)
    print(2,3,4)     // void print<int, int, int>(int head, int rest, int rest)     后面的rest， rest 就是 rest...
    print(3,4)
    print(4)
    print() // 调到此函数时， 递归终止了
    */

   /*
    parameter 1
    parameter 2
    parameter 3
    parameter 4
    empty
   */
    /*
    parameter 1
    parameter 2
    parameter 3
    4
    */

   cout << sum(1,2,3,4) << endl;
   cout << sum(1,2,3,4,5,6,7,8,9,10) << endl;


    cout << fun<int>(4.4) << endl; //fun<int, float>(4.4)
    cout << fun<float>(4.4) << endl; //fun<float, float>(4.4)
    cout << fun<int>(4) << endl; //fun<int, int>(4)

    return 0;
}

