#include <iostream>

using namespace std;

double divide(int a, int b) {
    if (b == 0)
        throw "dividor can not be zero";
    return double(a) / b;
}


int main()
{
    int x, y;
    cout << "please ennter two num:";
    while (cin >> x >> y)
    {

        try {
            cout << x << "/" << y << "=" << divide(x, y) << endl;
        }
        catch(const char* s) {
            cout << s << endl;
            cout << "please enter another two num :" << endl;
            //continue;
        }
    }
    return 0;

}
