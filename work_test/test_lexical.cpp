#include <iostream>  
#include <boost/lexical_cast.hpp>  
#include <string>
using namespace std;  
using namespace boost;  

template<typename T2, typename T1>
inline T2 my_lexical_cast(const T1 &in) {
    T2 out;
    cout << in << endl;
    std::stringstream ss;
    ss << in;
    ss >> out;
    cout << out << endl;
    return out;
}


int main()  
{  
    string s = "123";  
    int a = my_lexical_cast<int>(s);
    int d = 2 * a;  
    cout << d << endl;
    double b = lexical_cast<double>(s);  
    string s1 = "123";
    if (s1.substr(0, 2) == "0x")
    {
             s1 = to_string(stoi(s1, nullptr, 0));
    }
    //int c;
    //std::stringstream ss;
    //ss << s1;
    //ss >> std::hex >> c;
    auto c = lexical_cast<int>(s1);
    cout << "c " << c << endl;
    printf("%d/r/n", a + 1);  
    printf("%lf/r/n", b + 1);  
  /*
    try 
    {  
	//为了防止转化错误使用一个错误的例子
        int c = lexical_cast<int>("wrong_number");  
    }  
    catch(bad_lexical_cast & e)  
    {  
        printf("%s/r/n", e.what());  
    }  
    */
    return 0;
} 
