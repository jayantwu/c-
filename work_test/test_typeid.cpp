#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>

struct A {
    virtual ~A() {}
};
 
struct B : A {};
struct C : A {};
 
int main()
{
    std::unordered_map<std::type_index, std::string> type_names;
 
    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";
 
    int i;
    double d;
    A a;
 
    // 注意我们正在存储指向类型 A 的指针
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);
 
    std::cout << "i is " << type_names[std::type_index(typeid(i))] << '\n';
    std::cout << "d is " << type_names[std::type_index(typeid(d))] << '\n';
    std::cout << "a is " << type_names[std::type_index(typeid(a))] << '\n';
    std::cout << "b is " << type_names[std::type_index(typeid(*b))] << '\n';
    std::cout << "c is " << type_names[std::type_index(typeid(*c))] << '\n';


    int aa;
    std::cout << std::hex << &aa << std::endl;
    int bb;
    new (&aa) int(55);  //定位new
    std::cout << std::hex << &aa << std::endl;

    std::cout << aa << std::endl;

    std::cout << typeid(aa).name() << " " << typeid(B).name() << std::endl;  // i 1B


    test v;
   //v.aaa = 55;
    






}
    