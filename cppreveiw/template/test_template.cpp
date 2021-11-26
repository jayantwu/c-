#include <iostream>
#include <string>
using namespace std;
template <typename T, int N>   // type-constrait
class A{
    public:
        void print()
        {
            cout << N << endl;
        }
    private:
        T t;    
};


template <typename T1,  typename T2>
class B {

    public:
        //B(T1 b, T2 c):_b(b), _c(c){}
        B()=default;
        T1 _b;
        T2 _c;

};

template <typename T1, typename T2, char S, int N>   // 非类型模板参数不能时类类型或者浮点数
class C : public B<T1, T2>
{
    public:
        C(T1 x, T2 y): a(x), b(y), num(N), s(S) {}
        void show()
        {
            cout << a << " " << b << " " << num << " " << s << endl;
        }

    private:
        T1 a;
        T2 b;
        int num;
        char s;

};

template <typename T>    //template alias
using B1 = B<T, int>;


template <char S, int N>
using C1 = C<string, int, S, N>;  //原来的type T1 T2实例化了：string 和 int


template <typename T = int>
void fun(T a)
{
    cout << a << endl;
}


int main()
{
    A<int, 5> a;
    a.print();

    //B1<int> b1;
    //B<int, int> b;

    C<string, int, 'a', 5> c("hi", 11);
    c.show();   // hi 11 5 a
    C1<'a', 5> c1(string("hi"), 11);   // hi 11 5 a
    c1.show();

    fun<int>(2.3);  // 2
    fun(2.3);   // 2.3
    fun<double>(2.3); // 2.3 


}

