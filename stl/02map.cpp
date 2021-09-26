#include <iostream>
#include <map> //使用 map 容器，必须引入该头文件
#include <string>
#include<utility>
using namespace std;

int main()
{
    map<string, int> mymap;
    mymap["tony"] = 98;
    mymap["lory"] = 76;
    mymap["lili"] = 87;
    mymap["sam"] = 91;
    
    for (map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        cout << it->first << ": " << it->second << endl;

    cout << "**********" << endl;
    for (auto  it : mymap)    //按照key的字典序排列
        cout << it.first << ": " << it.second << endl;

    cout << "**********" << endl;
    for (auto  &it : mymap)    //referance 
        it.second += 1;

    for (auto  it : mymap)
        cout << it.first << ": " << it.second << endl;

    cout << "**********" << endl;
    mymap.insert(map<string, int>::value_type("nick", 88));

    for (auto  it : mymap)
        cout << it.first << ": " << it.second << endl;
    cout << "**********" << endl;
    mymap.insert(pair<string, int>("katty", 76));   //pair
    for (auto  it : mymap)
        cout << it.first << ": " << it.second << endl;    


    cout << "**********" << endl;
    mymap.insert(make_pair<string, int>("jeck", 100));  //make_pair
    for (auto  it : mymap)
        cout << it.first << ": " << it.second << endl; 
    cout << "**********" << endl;
    mymap.erase("lili");
     for (auto  it : mymap)
        cout << it.first << ": " << it.second << endl; 

    cout << "**********" << endl;
   auto itr = mymap.find("nick");
   cout << itr->first << ": " << itr->second << endl;      
    
}


/*
lili: 87
lory: 76
sam: 91
tony: 98
**********
lili: 87
lory: 76
sam: 91
tony: 98
**********
lili: 87
lory: 76
sam: 91
tony: 98

*/