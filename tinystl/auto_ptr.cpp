// 一个具有严格对象所有权的小型智能指针
template <class T>
class auto_ptr
{
public:
  typedef T    elem_type;

private:
  T* m_ptr;  // 实际指针

public:
  // 构造、复制、析构函数
  explicit auto_ptr(T* p = nullptr) :m_ptr(p) {}  //构造函数，不允许进行类型转化，只用来构造
  auto_ptr(auto_ptr& rhs) :m_ptr(rhs.release()) {}  //复制构造函数
  template <class U>  //模板复制构造函数
  auto_ptr(auto_ptr<U>& rhs) : m_ptr(rhs.release()) {}  //rhs.m_ptr指向空，原来的指针赋给新的对象

  auto_ptr& operator=(auto_ptr& rhs)  //赋值操作
  {
    if (this != &rhs)  //不是同一个对象
    {
      delete m_ptr;   //先释放this->m_ptr;
      m_ptr = rhs.release();  //this->m_ptr = rhs.release();
    }
    return *this;
  }
  template <class U>  //模板的operator=重载
  auto_ptr& operator=(auto_ptr<U>& rhs)//不同类型之间指针的赋值操作
  {
    if (this->get() != rhs.get())
    {
      delete m_ptr;
      m_ptr = rhs.release();
    }
    return *this;
  }

  ~auto_ptr() { delete m_ptr; }

public:
  // 重载 operator* 和 operator->
  T& operator*()  const { return *m_ptr; }
  T* operator->() const { return m_ptr; }  //相当于m_ptr->

  // 获得指针
  T* get() const { return m_ptr; }

  // 释放指针
  T* release()
  {
    T* tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
  }

  // 重置指针
  void reset(T* p = nullptr)
  {
    if (m_ptr != p)
    {
      delete m_ptr;  //原来的指针先 释放掉
      m_ptr = p;
    }
  }
};

} // namespace mystl