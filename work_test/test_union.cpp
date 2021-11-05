#include <iostream>
int main()
{
    union
    {
        int a;
        const char* p;
    };
    a = 1;
    p = "Jennifer";
}