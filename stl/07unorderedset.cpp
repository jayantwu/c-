#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int check_n(int n)
{
    if (n > 10)
    {
        return 1;
    }
    else    
    {
        return 0;
    }
}

int main()
{
#if 0
    int rc = 999;
    if ((rc = check_n(99)) == 0)
    {
        cout << "n is < 10" << endl;
    }
    else if ((rc = check_n(99)) == 0)
    {
        cout << "n is < 10" << endl;
    }
    else
    {
        cout << rc << endl;

        return rc;
    }
#endif
    vector<uint32_t> v {1111, 2222, 3333, 4444};
    string s;
    for (auto i : v)
    {
        s += "[" + to_string(i) + "]";
    }
    cout << s << endl;

}
