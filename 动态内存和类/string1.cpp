#include<cstring>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const char *s)  //将c字符串转成类 
{
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_strings++;	
}

String::String() 
{
	len = 4;
	str = new char[1];
	str = '\0';   //为了调用析构函数时可以统一处理 delete [] str; 
	num_strings++;
}


String::String(const String & st)  //拷贝构造函数 
{
	num_strings++;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
}


String::~String()
{
	--num_strings;
	delete [] str;
	
}




//运算符重载---对象的赋值 
String & String::operator=(const String &st)
{
	if (this == &st)
		return  *this;
	delete [] str;   //先将原来指向的内存释放，重新开辟新的内存 
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	return  *this;
} 

String & String::operator=(const char *s)   //将c风格字符串赋值给string对象 
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;      //返回对象本身的引用 
}

char & String::operator[](int i)
{
	return str[i];    //可读可写 
	
} 


const char & String::operator[](int i)const
{
	return str[i];   //const限定只读  不能修改私有类成员 
} 


//友元函数重载

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}


bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
	
}


bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}



ostream & operator<<(ostream & os, const String &st)
{
	os << st.str;
	return  os;
}

istream & operator>>(istream & is, String &st)
{
	char temp[String::CINLIM];
	is.get(temp,  String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}


 
