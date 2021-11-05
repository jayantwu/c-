#include<iostream>
#include<vector>
using namespace std;

class testA
{
    string name;
    int a;
    vector<int*> v;
    public:
        testA(const string &s, const vector<int*> & int_v)
        : name(s)
        {
            a = *(int_v[0]);
        }

        testA(const string & s)
        : testA(s, vector<int*>({new int(55)}))
        {

        }

        void show()
        {
            cout << name << ": " << a << endl;
        }

        int &operator() ()
        {
            return a;
        }


};


int main()
{
    testA a("wujiayang");
    a.show();
    testA b = testA("frank");
    b.show();

    cout << "use () to return a: " << a() << endl;  // use () to return a: 55
    
    vector<int*> vv = vector<int*> ({new int(55), new int(66)}); // 2 element
    for (auto it : vv)
        cout << "vv= "<< *it << endl;


    vector<int> v = vector<int>({1, 2, 3});
    for (auto i : v)
        cout << "v=" << i << endl;
}