#include <iostream>
using namespace std;
void process(const int & x)
{
    cout << "left" << endl;
}

void process(int && x)
{
    cout << "right" << endl;

}


template <typename T>
void test(T && prama)   //模板中这个是通用引用，左值右值都能接受 不是右值引用！！引用折叠（reference collapse）
{
    process(forward<T>(prama));  //根据接收到的类型，传给process
}


template <typename T, typename U>
void perfectForward(T && t, U & F) {
    cout << t << "\t forwarded..." << endl;
    //cout << __func__ << endl;   //可以打印函数自己的name
    F(forward<T>(t));
}

void run1(double && d1){}
void run2(double && d2){}
void run3(double && d3){}


int main()
{
    int a = 3;
    test(a);
    test(move(a));

    // 将rval 1.5 转给run1， run1只接受右值
    perfectForward(1.5, run1);  // 1.5	 forwarded...
    perfectForward(2, run1);

}


