#include <iostream>

using namespace std;

class libriry {
public:
    //做特定任务，有固定的流程，一些方法需要子类去实现
    void run()  //run是稳定的函数
    {
        step1();
        step2();  //变化的，需要子类overide
        step3();
    }
    virtual ~libriry(){};

protected:
    void step1() { cout << "step1" << endl; }
    void step3() { cout << "step3" << endl; }

    virtual void step2() { cout << "libriry step2" << endl; };  // 放在子类实现

};


class application : public libriry {
protected:
    void step2() { cout << "app step2" << endl; }
};


int main()
{
    libriry *ptr_app1 = new application();   //多态
    ptr_app1->run();
    delete ptr_app1;
}

