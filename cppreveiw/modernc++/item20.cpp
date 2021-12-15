#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
using std::make_shared;


class A {

};


int main()
{

    auto sptr = make_shared<A>();
    weak_ptr<A> wptr(sptr);   // use shared_ptr initilize weak_ptr
    sptr = nullptr;
    if (wptr.lock() == nullptr)  //lock() will return a shared_ptr(), if weak_ptr is expired , it will return nullptr
        cout << "wptr is null" << endl;

    try
    {
        shared_ptr<A> sptra(wptr);  //用weak_ptr初始化shared_ptr, if weak_ptr is expired, it will raise a exception
    }
    catch (std::bad_weak_ptr &e)
    {
        cout << e.what() << endl;
    }
    

    return 0;

}
