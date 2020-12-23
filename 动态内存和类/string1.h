#include<iostream>
#ifndef STRNG1_H_
#define STRNG1_H_
using std::ostream;
using std::istream;

class String{
	private:
		char *str;
		int len;
		
		static int num_strings;
		static const int CINLIM = 80;
	public:
		String(const char*s);  //可以用作类型转换函数 
		String();  
		String(const String&); //拷贝构造函数
		~String();
		int length()const {
			return len;
		};
		
		//运算符重载  成员函数 
		String & operator=(const String &);
		String & operator=(const char*);
		char & operator[](int i);
		const char & operator[](int i)const;
		
		//运算符重载  友元函数
		friend bool operator<(const String &st1, const String &st2);
	    friend bool operator>(const String &st1, const String &st2);
	    friend bool operator==(const String &st1, const String &st2);
	    friend ostream & operator<<(ostream & os, const String &st);
	    friend istream & operator>>(istream & is, String &st);
	    //静态成员函数
		static int HowMany(); 
		 
};
#endif