#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    unordered_map<string, int> umap;
    //umap.emplace("tony", 15);
    //umap.emplace("lisa", 16);
    umap["tony"] = 15;
    umap["lisa"] = 16;
    umap["nick"] = 17;
    umap.emplace("rick", 14);
    cout << "size is " << umap.size() << endl;
    umap.emplace("rick", 15);  //will not add to

    for (auto it = umap.begin(); it != umap.end(); it++)
        cout << it->first << ": " << it->second << endl;


    cout << umap.at("tony") << endl;
    cout << umap.at("nick") << endl;


    unordered_map<string,double> mymap = {
     {"mom",5.4},
     {"dad",6.1},
     {"bro",5.9} };

     unordered_map<std::string,double>::const_iterator got = mymap.find("dad");

    if ( got == mymap.end() )
        cout << "not found";
    else
        cout << got->first << " is " << got->second << endl;


    if (mymap.count("mom"))   //will return 0 or 1 for unordered map
        cout << "exist mom" << endl;
    else
        cout << "not exit";
    // test bucket()
    std::unordered_map<std::string,std::string> myumap = {
    {"us","United States"},
    {"uk","United Kingdom"},
    {"fr","France"},
    {"de","Germany"}
  };

  for (auto& x: myumap) {
    std::cout << "Element [" << x.first << ":" << x.second << "]";
    std::cout << " is in bucket #" << myumap.bucket(x.first) << std::endl;
  }

    


}