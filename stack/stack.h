#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};  //用枚举作为类的符号常量 ,作用域为类 
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif