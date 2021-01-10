#include <iostream>

using namespace std;

class A
{
	private:
		int* age;
	public:
		A()
		{
			age = new int;
			*age = 0;
			cout << "A()\n";
		}
		A(const A & a)
		{
			//*this = a;
			age = new int;
			*age = *(a.age);
			cout << "A(const A &)\n";
		}
		A(int n)
		{
			age = new int;
			*age = n;
			cout << "A(int n)\n";
		}
		~A()
		{
			delete age;
			cout << "~A()\n";
		}
		void show()
		{
			cout << *age << endl;
		}
		A & operator=(const A &a)
		{
			delete age;
			age = new int;
			*age = *(a.age);
			return *this;
		}
		
		
};


int main()
{
	A a(2);
	//A b(a);
	A c;
	c = a;
	
	//b = a;
	a.show();
	//b.show();
	c.show();
	//A b(a);
}