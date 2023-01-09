#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;



int main(){
    unordered_set<uint32_t> set1;
    set1.insert(1);
    set1.insert(2);

    for (auto i : set1) {
        cout << i << endl;
    }


    vector<int> v {1,2,3};

    cout << v[3] << endl;
}