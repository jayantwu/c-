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


template <typename T>
struct HexT {
    T value;
    operator T() const {return value;}  //用作隐式类型转换， cout<< 时可以用
    friend std::istream& operator>>(std::istream& in, HexT& out) {   //要定义输入流 lexical_cast要求类型需要有这个操作
        in >> std::hex >> out.value;
        return in;
    }
};



int main()  
{  
    string s = "123";  
    int a = my_lexical_cast<int>(s);
    int d = 2 * a;  
    cout << d << endl;
    double b = lexical_cast<double>(s);  
    string s1 = "0x123";
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

    cout << endl;
    string s2 = "0x123";
    string s3 = "123";
    HexT<int> ret = lexical_cast<HexT<int>>(s2);
   //cout << int(ret) << endl; //不需要显式
    cout << ret << endl;
    auto ret2 = lexical_cast<HexT<int>>(s3); // "123" will treat as 0x123
    cout << ret2<< endl;
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
