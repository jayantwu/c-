#include <memory>
#include <iostream>
using namespace std;
int main()
{
    unique_ptr<int> up1(new int(11));   //up1 point a memory, the val is 11
    //unique_ptr<int> up2 = up1;  //can't pass the compile

    cout << *up1 << endl;  //11

    unique_ptr<int> up3 = move(up1);   //call up3 move ctor, up1 transfer to up3

    cout << *up3 << endl;
    //cout << *up1 << endl;   //running error! segmemtation fault, up1 is 'nullptr'
    up3.reset();  //explict release memory
    up1.reset();   //no error
    
    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << endl;  //22
    cout << *sp2 << endl;  //22

    sp1.reset();  //reference cnt decrease by 1
    cout << *sp2 << endl;  //22





    return 0;

}