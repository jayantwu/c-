#include "location.h"
#include<iostream>


Location::Location(int a, int b)
{
    x = a;
    y = b;
    std::cout << "call Location(int a, int b)\n";
}



Location::~Location()
{
    std::cout << "call ~Location()\n";
}

void Location::showlocation()
{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}


int Location::getx()
{
    return x;
}

int Location::gety()
{
    return y;
}


// increase a and b
void Location::addmove(int a, int b)
{
    x += a;
    y += b;
}