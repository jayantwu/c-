#include <boost/dynamic_bitset.hpp>
#include <iostream>
int main()
{
    boost::dynamic_bitset<> x(5); // all 0's by default
    x[0] = 1;   //x[0] is the most left bit
    x[1] = 1;
    x[4] = 1;
    for (boost::dynamic_bitset<>::size_type i = 0; i < x.size(); ++i)
        std::cout << x[i];     // 11001
    std::cout << "\n";
    std::cout << x << "\n";  // 10011
    std::string s = "0011011000111";
    boost::dynamic_bitset<> y(s);
    std::cout << y << std::endl;   // 0011011000111

    boost::dynamic_bitset<> z(10,5);   //10 bits val=5
    std::cout << z << std::endl;   // 0000000101
    std::string ss;
    boost::to_string(z, ss);
    std::cout << "ss: " << ss << std::endl;


    boost::dynamic_bitset<> w(10);
    w.set();
    std::cout << w << std::endl;    // 1111111111

    w.reset();
    std::cout << w << std::endl;  // 0000000000

    boost::dynamic_bitset<> a(std::string("0011"));
    boost::dynamic_bitset<> b(std::string("0011"));

    if (a == b)
        std::cout << "a equals b" << std::endl;


    std::cout << a << std::endl;




    return EXIT_SUCCESS;
}