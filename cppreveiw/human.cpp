#include "human.h"
#include<iostream>



void Human::say(std::string & word)
{
    std::cout << word << std::endl;
}

void Human::say(char * w)
{
    std::cout << w << std::endl;
}


Location& Human::getlocation()
{
    return _location;
}

void Human::walk(int a, int b)
{
    _location.addmove(a, b);
}



