#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    vector<int> v1 {5, 5, 5};
    vector<int> v2 {1,1,1,1,1,1,1,1,1};
    vector<int> v3 {1, 2, 3};
    v2.insert(v2.begin()+1, v1.begin(), v1.end());
    v1.insert(v1.end(), {6});
    for (auto i : v1){
        cout << i << endl;
    }
    cout << endl;
    //cout << v2 << endl;
    for (auto i : v2)
        cout << i << "";
    cout << endl;


    cout << " v3[3]=" <<v3[3] << endl;

}


