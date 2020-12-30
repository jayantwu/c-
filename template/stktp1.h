#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
	private:
		enum {SIZE  = 10};
		int stacksize;
		Type *items;
		int top;
	public:
		explicit Stack(int ss = SIZE);   //加了explicit 禁止隐式类型转换，因为没有意义
		Stack(const Stack &  st);    //拷贝构造函数 
		~Stack(){
			delete [] items;
		} 
		bool isempty(){
			return top == 0;
		}
		bool  isfull(){
			return top == stacksize;
		}
		bool push(const Type & item);
		bool pop(Type & item);
		Stack & operator=(const Stack & st);

};

template <class Type>
Stack<Type>::Stack(int ss):stacksize(ss), top(0)
{
	items = new Type [stacksize];
} 


template <class Type>
Stack<Type>::Stack(const Stack& st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type [stacksize];
	for (int  i = 0; i < top; i++)
		items[i] = st.items[i];   //逐个赋值 
}


template <class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
} 


template <class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}


template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
	if (this  == &st)
		return *this;
	//不同于拷贝构造函数的地方，赋值运算需要先释放items的内存 ，因为赋值时左边的对象至少已经通过默认构造函数是动态分配过内存的
	//所以需要先释放 
	delete [] items;    
	stacksize = st.stacksize;
	top = st.top;
	items = new Type [stacksize];
	for (int  i = 0; i < top; i++)
		items[i] = st.items[i];   //逐个赋值 
	return *this;
}


#endif