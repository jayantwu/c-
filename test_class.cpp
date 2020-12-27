#include <iostream>
using namespace std;
static int n = 1;
static int m = 1;
class A
{
	private:
		int a;
	public:
		A(int num1);
		A(const A & aa); 
		A();
		~A();
		A operator+(const A & aa)const;
		const A& isbigger(const A & aa)const; 
		friend A operator+(int n, const A & aa);
		friend ostream & operator<<(ostream &os, const A & aa);
		
};
/**************************************************/
//类的实现 
A::A(int num1)  //这个构造函数也可以被用来将int型转成A，可以隐式或显式 
{
	a = num1;
	cout << m <<":use A(int )\n";
	m++;
}

A::A()
{
	cout << m <<":use A()\n";
	m++;
}

A::A(const A & aa)
{
	cout << m << ":use A(const A &)\n";
	m++; 
} 

A::~A()
{
	
	cout << n << "：use ~A()\n";
	n++; 
} 

A A::operator+(const A & aa)const
{
	return A(a+aa.a);
}

const A & A::isbigger(const A & aa)const
{
	if (a > aa.a)
		return *this;
	else 
		return aa;
}

ostream & operator<<(ostream & os, const A & aa)
{
	os << aa.a << endl;
	return os;
}

A operator+(int n, const A & aa)    
{
	//return A(aa.a + n);
	return aa + n;    //以这种方式返回，可以不声名为友元函数 
}

/**************************************************/


/*************************************************/ 
//主函数 
int main()
{  
	A aa(5);
	A bb(10);
	cout << "aa: " << aa << endl;
	cout << "bb: " << bb << endl;

	cout << "aa+bb: " << aa+bb << endl;	

	
	A c = aa + 6;  //aa.operator+(const A  & aa) 返回一个A的对象 
	cout << "c: " << c << endl;
	A d = 6 + aa;  //调用友元函数 
	cout << "d: " << d << endl;
	A big = aa.isbigger(bb);   //会调用拷贝构造函数 
	cout << "big: " << big << endl;
	
	A e = 15;   //用构造函数隐式转换   //或者显式  A e = A(15); 
	cout << "e: " << e << endl;
	
	A f;  //调用了A()默认构造函数 
}
/*************************************************/ 





/*
调用了10次构造函数和10次析构函数 
1:use A(int )
2:use A(int )
aa: 5

bb: 10

3:use A(int )
aa+bb: 15

1：use ~A()
4:use A(int )
5:use A(int )
2：use ~A()
c: 11

6:use A(int )
7:use A(int )
3：use ~A()
d: 11

8:use A(const A &)
big: 1

9:use A(int )
e: 15

10:use A()
4：use ~A()
5：use ~A()
6：use ~A()
7：use ~A()
8：use ~A()
9：use ~A()
10：use ~A()







*/