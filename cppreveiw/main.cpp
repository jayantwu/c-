#include <iostream>
#include "human.h"
using namespace std;
int main()
{
    Human A("wujiayang", 25, Location(0, 0), MALE);
    string word = "hello guys!";
    A.say(word);
    //A.say("hi everyone");

    Location point0 = A.getlocation();
    point0.showlocation();

    A.walk(3,4);
    A.getlocation().showlocation();

    Human B("lory", 27, Location(6, 5), FEMALE);
    cout << B.name() << ": " << B.age() << endl;




}