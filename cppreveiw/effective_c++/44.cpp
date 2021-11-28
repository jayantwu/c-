#include <iostream>

using namespace std;
template <typename T>
class matrixbase {
    protected:
        void invert(int n)
        {
            cout << "invert matrix" << endl;
        }
    public:
        void show()
        {
            cout << "this is base show" << endl;
        }
};


template <typename T, int n>
class matrix : private matrixbase<T> {
    private:
        using matrixbase<T>::invert;    // 不using声明的话， 派生类看不到基类调这个成员函数
    public:
        //using matrixbase<T>::invert;   // 不能放在这里，否则invert(n)从外部也能调
        void invert() { return invert(n); }
        using matrixbase<T>::show;
        void showa() { show(); }
};


template <typename T>
class A {
public:
    void show(T a)
    {
        cout << "this is A.show(T a) " << a << endl;
    }
    void show() {
        cout << "this is A.show()" << endl;
    }
};

template <typename T>
class B : public A<T> {
public:
    using A<T>::show;
    void show() {
        cout << "this is B.show()" << endl;
        //this->show();   // if no using declare, use this is ok
    }
};


int main()
{
    matrix<int, 5> m1;
    m1.invert();
    matrix<double, 10> m2;
    m2.invert();
    m2.showa();
    //m1.invert(5);

    B<int> b;
    b.show(5);  // A::show(T a)
    b.show();    // B::show()

}