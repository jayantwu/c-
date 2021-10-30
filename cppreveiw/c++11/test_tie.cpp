#include <iostream>
#include <string>
#include <set>
#include <tuple>
 
struct S {
    int n;
    std::string s;
    float d;
    bool operator<(const S& rhs) const
    {
        // compares n to rhs.n,
        // then s to rhs.s,
        // then d to rhs.d
        return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
    }
};
 
int main()
{
    std::set<S> set_of_s; // S is LessThanComparable
 
    S value{42, "Test", 3.14};
    std::set<S>::iterator iter;
    bool inserted;
 
    // unpacks the return value of insert into iter and inserted
    std::tie(iter, inserted) = set_of_s.insert(value);  //insert will return pair<set<S>::iterator, bool>
    std::cout << iter->n << " " <<  iter->s << " " << iter->d << " " << inserted << std::endl;
    std::cout << inserted << std::endl;
    if (inserted)
        std::cout << "Value was inserted successfully\n";
}