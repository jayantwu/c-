#include "human.h"
#include<iostream>

Human::Human(std::string n, int num, int a, int b): name(n), age(num),location(a, b)
{

}


Human::~Human()
{

}


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
    return location;
}

void Human::walk(int a, int b)
{
    location.addmove(a, b);
}



