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
    auto p3 = new A();
    vector<shared_ptr<A>> ptra_v;
    ptra_v.emplace_back(p3);  // 一般不要将 raw pointer的变量直接给shared_ptr的构造函数
    //ptra_v.emplace_back(p3);  //错误的做法，这样指针会释放两次， p3所指的对象会有两份control block
    vector<A*> ptra_v2;
    ptra_v2.push_back(new A());
    auto p4 = new A();
    auto ptr1 = shared_ptr<A>(p4);
    //auto ptr2 = shared_ptr<A>(p4);

    return 0;

}
