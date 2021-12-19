#include "05test.h"

using namespace l1;
int main()
{
    
    Base* ptr_b = new Drive();
    Base* ptr_c = new l2::l3::DDrive();
    ptr_b->peek();   // derived read

}



