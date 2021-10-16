#include <iostream>
#include "human.h"
using namespace std;
int main()
{
    Human A("wujiayang", 25, 0, 0);
    string word = "hello guys!";
    A.say(word);
    //A.say("hi everyone");

    Location point0 = A.getlocation();
    point0.showlocation();

    A.walk(3,4);
    A.getlocation().showlocation();

    Human B("lory", 27, 6, 5);
    cout << B.getname() << ": " << B.getage() << endl;




}