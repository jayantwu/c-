#include <iostream>

using namespace std;
//目标接口（新接口）
class ITarget{
public:
    virtual void process()=0;
};

//遗留接口（老接口）
class IAdaptee{
public:
    virtual void foo(int data)=0;
    virtual int bar()=0;
};

//遗留类型, 老接口的实现
class OldClass: public IAdaptee{
private:
    int a;
public:
    OldClass(int v) : a(v) {}
    virtual void foo(int data) {
        cout << data << endl;
    }
    virtual int bar() {
        return a;
    }
};

//对象适配器
class Adapter: public ITarget{ //继承， 要实现ITarget的接口， process()
protected:
    IAdaptee* pAdaptee;//组合, has a , 相当于继承了实现
public:
    Adapter(IAdaptee* pAdaptee){
        this->pAdaptee=pAdaptee;
    }
    virtual void process() {
        int data=pAdaptee->bar();  //调用了OldClass的bar()
        pAdaptee->foo(data);       //调用了OldClass的foo()
    }
    
};


int main(){
    IAdaptee* pAdaptee = new OldClass(5);
    // main函数中要使用新的接口
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget->process();
}










