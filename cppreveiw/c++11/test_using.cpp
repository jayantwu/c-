#include <unordered_map>
#include <string>
#include<iostream>
using namespace std;

void* fun(int x, int y);
using pfun_t = void* (*)(int, int);   // to define a func pointer type, it's more clear than using typedef
int main()
{
    using Map = unordered_map<string, int>; // just like " typedef unordered_map<string, int> Map;  "
    Map a;
    a.insert(pair<string , int>("wujiayang", 20));
    for (auto i : a)
    {
        cout << i.first << ": " << i.second << endl;
    }
    pfun_t myfun = fun;
    myfun(1, 2);

}


void* fun(int x, int y)
{
    cout << "i am a fun\n";
    cout << x << y << endl;
    return nullptr;
}