#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class  beta
{
	private:
		template <typename V>    //成员模板 
		class hold
		{
			private:
				V  val;
			public:
				hold(V v = 0): val(v){
					
				}
				void show() const {
					cout << val << endl;				
				}
				V Value() const {
					return val;
				}
		};
		hold<T> q;  //q 和n都是hold 的对象，类型为T和int 调用了hold的构造函数初始化，并作为了beta的成员数据 
		hold<int> n;
	public:
		beta(T t,  int i): q(t), n(i){  //调用hold的构造函数 
			
		}
		template<typename U>   //成员模板函数 
		U blab(U u, T t){
			return (n.Value() + q.Value()) * u / t;
		}
		void Show() const {
			q.show(); n.show();
		}
		
};


int main()
{
	beta<double> guy(3.5, 3);  // T设置为double 调用了beta的构造函数， 
	cout << "T was set to double\n";
	guy.Show();
	cout  << "V was set to T, which is double, then V was set  to int\n";
	cout <<  guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n" << endl;
	cout <<  guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n" << endl;
	cout << "Done!\n";
	return  0;
} 