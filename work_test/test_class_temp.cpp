#include <iostream>
#include <string>
#include <vector>
using namespace std;



template <typename T1, typename T2>
class Pair{

    private:
        T1 a;
        T2 b;

    public:
        Pair(const T1 & x, const T2 & y):a(x), b(y){}    //need use const T & , so it can receive r val
        Pair(){}

        T1& first();
        T2& second();

};

template<typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template<typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

int main()
{
    string name = "Ned";
    Pair<string, int> p2("Ned", 33);
    Pair<string, int> p1(name, 33);
    cout << p1.first() << ": " << p1.second() << endl;
    vector<Pair<string, int>> v;
    v.push_back(p1);
    cout << v.front().first() << endl;
    
}


