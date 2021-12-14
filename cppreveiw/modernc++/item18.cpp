#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
class A {

};


unique_ptr<A> makeA()
{
    unique_ptr<A> ptra(nullptr);
    ptra.reset(new A());
    return ptra;
}

auto delfun = [](A* ptra)    // custom deleter
{
    delete ptra;
    cout << "delete A" << endl;
};

unique_ptr<A, decltype(delfun)> makeA1()
{
    unique_ptr<A, decltype(delfun)> ptra(nullptr, delfun);
    ptra.reset(new A());
    return ptra;
}


int main()
{
    auto p = makeA();

    auto p1 = makeA1();
    return 0;
}
