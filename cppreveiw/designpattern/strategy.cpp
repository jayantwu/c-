#include <iostream>

using namespace std;
class texstrategy {  //不变的抽象类
public:
    virtual void calculate()=0;
    virtual ~texstrategy() {}
};

class cntex : public texstrategy {  //可变化的
public:
    virtual void calculate() { cout << "cal cn tex" << endl; }

};

class ustex : public texstrategy {
public:
    virtual void calculate() { cout << "cal us tex" << endl; }
};


class detex : public texstrategy {
public:
    virtual void calculate() { cout << "cal de tex" << endl; }
};

//这个工厂后期再改
class strategyfactory {
public:
    texstrategy* newstrategy() {}
};

class saleorder { //不变的
private:
    texstrategy * strategy;
public:
    saleorder(strategyfactory* factory) {
        strategy = factory->newstrategy();
    }
    ~saleorder() { delete strategy; }

    void calculatetex() { 
        strategy->calculate();
    }
};


