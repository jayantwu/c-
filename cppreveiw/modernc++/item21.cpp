#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
using std::make_shared;

namespace test
{
template<typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params)
{
    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}

}

class A {
public:
    A(int x, int y): a(x), b(y){}
    void show()
    {
        cout << a << " " << b << endl;
    }
private:
    int a;
    int b;
};


int main()
{

    auto ptr = test::make_unique<A>(1, 2);
    ptr->show();

    auto spv = make_shared<vector<int>>(10, 20); //can't use initialized list
    for (auto i : *spv)
        cout << i << endl;   // will output ten 20
    cout << "--------" << endl;
    auto l = {10, 20};
    auto spv2 = make_shared<vector<int>>(l);
    for (auto i : *spv2)
        cout << i << endl;  // will output 10 20
    return 0;

}


