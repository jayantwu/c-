//模板类的约束模板友元函数

#include <iostream>
using namespace std;

template <typename T> void  counts();
template <typename T> void reports(T&);

template <typename TT>
class HasFriendT
{
	private:
		TT item;
		static int ct;
	public:
		HasFriendT(const TT & i):item(i){   //每次调用这个构造函数生成对象时ct++ 
			ct++;
		}
		~HasFriendT(){
			ct--;
		} 
		friend  void counts<TT>();
		friend void reports<>(HasFriendT<TT> &);
};


template <typename T>
int HasFriendT<T>::ct = 0; //每个特定的具体化都有一个静态成员ct 


template <typename T>
void counts()
{
	cout <<  "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;	
} 

template <typename T>
void reports(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(1.2);
	reports(hfi1);  //转化为 reports(HasFriendT<int> &) 
	reports(hfi2);
	reports(hfdb);
	cout << "counts<int> output:\n";
	counts<int>();
	cout << "counts<double> output:\n";
	counts<double>();
	return 0;
}