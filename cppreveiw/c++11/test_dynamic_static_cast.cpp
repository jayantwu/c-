// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

int main () {
  try {
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);   //base pointer to derived pointer (pba point to derived)
    if (pd==0) cout << "Null pointer on first type-cast.\n";

    pd = dynamic_cast<Derived*>(pbb);    // pbb point to base
    if (pd==0) cout << "Null pointer on second type-cast.\n";


    Base * pbs;
    pbs = static_cast<Derived*>(pba); // right
    //pbs = static_cast<Derived*>(pbb);  // may be runtime error

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}




/*
dynamic_cast 只能够用在指向类的指针或者引用上(或者void*)。这种转换的目的是确保目标指针类型所指向的是一个有效且完整的对象。

同隐式转换一样，这种转换允许upcast(从派生类向基类的转换)。

但dynamic_cast 也能downcast(从基类向派生类的转换)当且仅当转过去的指针所指向的目标对象有效且完整。

https://zhuanlan.zhihu.com/p/151744661
*/