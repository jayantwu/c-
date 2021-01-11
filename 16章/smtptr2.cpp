#include <iostream>
using namespace  std;

template<typename T>
class Auto_ptr2
{
public:
    Auto_ptr2(T* ptr = NULL) :
        m_ptr(ptr)
    {}

    virtual ~Auto_ptr2()
    {
        delete m_ptr;
    }

    Auto_ptr2(Auto_ptr2& rhs)
    {
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = NULL;
    }

    Auto_ptr2& operator=(Auto_ptr2& rhs) 
    {
        if (&rhs == this)
            return *this;

        delete m_ptr; 
        m_ptr = rhs.m_ptr; 
        rhs.m_ptr = NULL; 
        return *this;
    }

    T& operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }
    bool isNull() const { return m_ptr == NULL; }
private:
    T* m_ptr;
};


class Resource
{
public:
    Resource() { cout << "Resource acquired!" << endl; }
    virtual ~Resource() { cout << "Resource destoryed!" << endl; }
};


int main()
{
    {
    	
    
	Auto_ptr2<Resource> res1(new Resource);
    Auto_ptr2<Resource> res2; // ��ʼ��Ϊnullptr

    cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res1; // ת��ָ������Ȩ

    cout << "Ownership transferred\n";

    cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
    }

    //cin.ignore(10);
    return 0;
}