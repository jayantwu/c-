#pragma once
#include <iostream>
using namespace std;
class FileSysterm
{
        int a;
        
    public:
        FileSysterm(int n):a(n){}
        void numDisks()const
        {
            cout << "disk num is " << a << endl;
        }
};