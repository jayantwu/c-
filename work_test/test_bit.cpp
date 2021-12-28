#include <iostream>
#include <boost/dynamic_bitset.hpp>
using namespace std;
using namespace boost;


dynamic_bitset<> writereg(int src, int pos, int size, int v)
{

    auto mask = 0;
    auto t = v << pos;
    while(--size >= 0)
    {    
        mask <<= 1;
        mask |= 1;
    }
    //cout << dynamic_bitset<>(32, mask) << endl;
    while(--pos >= 0)
        mask <<= 1;
    //cout << dynamic_bitset<>(32, mask) << endl;

    auto umask = ~mask;
    src &= umask;
    src |= (t & mask);
    return dynamic_bitset<>(32, src);
}


int main()
{
    auto ret = writereg(0b11111111111111, 5, 3, 5);
    cout << ret << endl;

    return 0;

}