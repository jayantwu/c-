#include <iostream>
#include <boost/dynamic_bitset.hpp>
using namespace std;
using namespace boost;


dynamic_bitset<> setbits(int src, int pos, int size, int v)
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

dynamic_bitset<> getbits(int src, int pos, int bsize, int &v)
{
    auto mask = 0;
    while (--bsize >= 0)
    {
        mask <<= 1;
        mask |= 1;
    }
    while (--pos >= 0) src >>= 1;

    v = src & mask;
    return dynamic_bitset<>(32, v);
}


int main()
{
    auto ret = setbits(0b11111111111111, 5, 3, 5);
    cout << ret << endl;
    int v = 0;
    auto f2 = getbits(0b11111110011011, 4, 2, v);
    cout << f2 << endl;
    return 0;

}