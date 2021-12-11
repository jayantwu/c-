#include <iostream>
using namespace std;



class NetworkState{  //抽象的状态基类

public:
    NetworkState* pNext;
    virtual void Operation1()=0;
    virtual void Operation2()=0;
    //virtual void Operation3()=0;

    virtual ~NetworkState(){}
};

class OpenState : public NetworkState{
private:  
    static NetworkState* m_instance;
    OpenState(){};
public:
    static NetworkState* getInstance(){
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }

    void Operation1() override;
    
    void Operation2() override;
    
    
    
};

NetworkState* OpenState::m_instance;

class CloseState : public NetworkState
{
private:  
    static NetworkState* m_instance;
    CloseState(){};
public:
    static NetworkState* getInstance(){
        if (m_instance == nullptr) {
            m_instance = new CloseState();
        }
        return m_instance;
    }

    void Operation1() override;
    
    void Operation2() override;
    
    
};

NetworkState* CloseState::m_instance;

class ConnectState : public NetworkState 
{
private:  
    static NetworkState* m_instance;
    ConnectState(){};
public:
     static NetworkState* getInstance(){
        if (m_instance == nullptr) {
            m_instance = new ConnectState();
        }
        return m_instance;
    }

    void Operation1() override;
    
    
    void Operation2() override;
    
    
};

NetworkState* ConnectState::m_instance;

void OpenState::Operation1()
{
    //**********
    pNext = CloseState::getInstance();
    cout << "from open to close" << endl;
}

void OpenState::Operation2()
{
    pNext = ConnectState::getInstance();
    cout << "from open to connect" << endl;
}


void CloseState::Operation1()
{
    //**********
    pNext = OpenState::getInstance();
    cout << "from close to open" << endl;
}

void CloseState::Operation2()
{
    pNext = ConnectState::getInstance();
    cout << "from close to connect" << endl;
}


void ConnectState::Operation1()
{
    //**********
    pNext = CloseState::getInstance();
    cout << "from Connect to close" << endl;
}

void ConnectState::Operation2()
{
    pNext = OpenState::getInstance();
    cout << "from connect to open" << endl;
}

class NetworkProcessor{
    
    NetworkState* pState;
    
public:
    
    NetworkProcessor(NetworkState* pState){  //传进来一个具体的状态
        
        this->pState = pState;
    }
    
    void Operation1(){
        //...
        pState->Operation1();
        pState = pState->pNext;   //state 更新
        //...
    }
    
    void Operation2(){
        //...
        pState->Operation2();
        pState = pState->pNext;
        //...
    }
    

};



int main()
{
    NetworkState* os = OpenState::getInstance();
    
    
    NetworkProcessor np(os);
    np.Operation1();  //在np的内部更新了pState的值
    np.Operation2();
    np.Operation2();


}


