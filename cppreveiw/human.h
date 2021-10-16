#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <string>
#include "location.h"


class Human
{
    private:
        std::string name;
        int age;
        Location location;

    public:
        Human(std::string n, int num, int a, int b);
        Human();
        ~Human();
        void say(std::string & word);    // print the word on screen
        void say(char* w);
        void look(); // not defined
        void walk(int a, int b);   //    from current location to a new location
        Location& getlocation();
        std::string getname(){
            return name;
        }
        int getage()
        {
            return age;
        }



};





#endif