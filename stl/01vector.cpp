#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> vec;
    for (int i = 0; i != 10; i++)
        vec.push_back(i);

    for (auto i : vec)   //range for loop
        cout << i << endl;


    int size = vec.size();
    cout << "size=" << size << endl;   //size=10
    int capacity = vec.capacity();
    cout << "capacity=" << capacity << endl;   //capacity=16

    return 0;
}


