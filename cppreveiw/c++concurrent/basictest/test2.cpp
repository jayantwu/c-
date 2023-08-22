#include "my.h"

using namespace std;

////// test std::move() //////

int main()
{

    vector<int> v1 {1, 2, 4};

    vector<int> v2 = move(v1);

    for (auto i : v2)
        cout << i << endl;
    
    cout << v1.size() << endl; // 0

    return 0;
}