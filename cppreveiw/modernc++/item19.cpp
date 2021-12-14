#include <iostream>
#include <vector>
//#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::vector;
class A {
public:
    void process();

private:
    vector<shared_ptr<A>> ptr_v; 
};


void A::process()
{
    //ptr_v.emplace_back(this);  //this 也是个raw pointer， 不能将raw pointer给shared_ptr
}

auto delfun = [](A* ptra)    // custom deleter
{
    delete ptra;
    cout << "delete A" << endl;
};

shared_ptr<A> makeA1()
{
    shared_ptr<A> ptra(nullptr, delfun);  // deleter as ctor's prama
    ptra.reset(new A());
    return ptra;
}


int main()
{
    auto p1 = makeA1();
    //auto p2 = new A();  //不要将raw pointer直接指向对象
    //shared_ptr<A> sp1(p2, delfun);  
    shared_ptr<A> p2(new A()); //应该这样，将创建出来的raw pointer 立即放入smt pointer 管理

    return 0;

}
