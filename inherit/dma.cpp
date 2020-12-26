#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char * l, int r)
{
	label = new char[std::strlen(l)+1];
	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)   //拷贝构造函数 
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}


baseDMA::~baseDMA()
{
	delete [] label;
} 

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
	
}


std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os; 
}



//lacksdma metheds
//派生类的构造函数，因为派生类无法直接访问基类的私有成员，因此使用了初始化列表的方式调用了基类的构造函数 
lacksDMA::lacksDMA(const char * c, const char * l, int r):baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

//派生类的复制构造函数 
lacksDMA::lacksDMA(const char * c, const baseDMA & rs):baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN] = '\0';	
} 


std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const baseDMA &)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
} 

//hasdma method;
hasDMA::hasDMA(const char *s, const char *l, int r):baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);	
}


hasDMA::hasDMA(const char * s, const baseDMA & rs):baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs)
{
	style  = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);	
}


hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);  //调用基类的赋值运算符，赋值属于基类 的部分
	delete [] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this; 
}


std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os <<  (const baseDMA &)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}



