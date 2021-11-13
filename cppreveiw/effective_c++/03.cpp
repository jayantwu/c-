#include <vector>
#include <string>
#include <iostream>
using namespace std;
class TextBlock{
    public:
        TextBlock(string s): test(s){}
        const char & operator[](size_t position)const{
            cout << "const version" << endl;
            return test[position];
        }
        char & operator[](size_t position){   // must return a ref
            cout << "non-const version" << endl;
            return test[position];
    }
    private:
        string test;

};


void print(const TextBlock& ctb)
{
    cout << ctb[0] << endl;
}

int main()
{
    vector<int> vec{1, 2};
    const vector<int>::iterator it = vec.begin(); // it like  T * const
    *it = 10;
    vector<int>::const_iterator it2 = vec.begin(); // it2 like  const T *
    //*it2 = 10;  //it's a const iterator

    vector<int> vec_c{1, 2, 3, 4};
    auto it3 = vec_c.cbegin();   //return a const iterator
    //*it3 = 10;
    vector<int>::const_iterator it4 = vec_c.cbegin();     //类型是匹配的


    TextBlock tb("Hello");
    cout << tb[0] << endl;   // non-const version
    tb[0] = 'x';   // non-const version
    const TextBlock ctb("world");
    cout << ctb[0] << endl;    // const version

    TextBlock tb2("hi");
    print(tb2); // const version





}