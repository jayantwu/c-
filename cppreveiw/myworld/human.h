#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <string>
#include "location.h"

enum SEX {
    MALE,
    FEMALE,
    UNKNOWN
};
class Human
{
    private:
        std::string _name;
        SEX _sex;
        int _age;
        Location _location;
    public:
        Human(std::string n, int a, Location p, SEX s = UNKNOWN) : _name(n),_age(a), _location(p), _sex(s) {}
        Human()=default;
        virtual ~Human()=default;
        virtual void say(std::string & word);    // print the word on screen
        virtual void say(char* w);
        virtual void look(){}; // not defined
        virtual void walk(int a, int b);   //    from current location to a new location
        Location& getlocation();
        SEX sex() { return _sex; }
        std::string name(){
            return _name;
        }
        int age()
        {
            return _age;
        }
};





#endif