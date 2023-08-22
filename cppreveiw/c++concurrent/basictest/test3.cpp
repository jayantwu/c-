#include "my.h"
#include <tuple>

using namespace std;

////// test template <typename ...Args> //////

template<typename ...Args>
void printArgs(Args... args)
{
    //cout << "num of args: " << sizeof...(args) << endl;
    // ((cout << args << " "), ...);  //this is c++17 feature
    tuple<Args...> mytpl(args...);
    cout << get<0>(mytpl) << endl;
    cout << get<1>(mytpl) << endl;
    cout << get<2>(mytpl) << endl;


    //cout << endl;
}



int main()
{

    printArgs(1, 2, "hello");

    return 0;
}