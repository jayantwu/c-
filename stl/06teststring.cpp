#include <string>
#include <iostream>


using namespace std;


int main()
{
    string s(20, '0');
    cout << s << endl;
    string s2;
    string s1 = string(5, '0') + "11100";
    s2 = s1;
    cout << s1 << endl;
    if (s == s1)
        cout << "....." << endl;

    else
        cout << "xxxx" << endl;

    bool b = s1 == s2;
    if (b == true)
        cout << b << endl;
}