#include<tuple>
#include<iostream>
using std::tuple;
using std::cout;
using std::endl;


tuple<int, double> myfun(int a, double b)
{
    return std::make_tuple(a, b);
}

int main()
{
    tuple<int, double> mytuple(1, 2.3);
    cout << std::get<0>(mytuple) << std::get<1>(mytuple) << endl;   // get<n>  n must be a constant val, can't be a var
    auto ret_tuple = myfun(1, 2);
    cout << std::get<0>(ret_tuple) << " " << std::get<1>(ret_tuple) << endl;
    return 0;

}