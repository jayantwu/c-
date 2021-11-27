#include <vector>
#include <deque>
#include <list>

using namespace std;

class TDconstructed {
private:
    template <typename T>   // 目标函数是一个模版构造函数
    TDconstructed(T first, T last): l(first, last) {}
    list<int> l;

public:
    // 委托构造函数
    TDconstructed(vector<short> & v) : TDconstructed(v.begin(), v.end()) {}  // T is vector<short>::iterator
    TDconstructed(deque<int> & d) : TDconstructed(d.begin(), d.end()) {} // T is deque<int>::iterator
};


int main()
{
    vector<short> vs;
    TDconstructed a = TDconstructed(vs);
}
