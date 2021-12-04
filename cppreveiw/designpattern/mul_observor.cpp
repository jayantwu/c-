#include <iostream>
#include <string>
#include <list>
#include <unistd.h>
using namespace std;

class Iprocess {   // this is important   //观察者
public:
    virtual void doprocess(float n)=0;
    virtual ~Iprocess() {}
};


class filesplit {  //这是一个稳定的类   // 目标 concrete subject
private:
    string m_filepath;
    int m_filenum;
    list<Iprocess*>  m_iprocesslist;     //支持多个observor
public:
    filesplit(const string filepath, int filenum):
    m_filepath(filepath),
    m_filenum(filenum)
    {}
    ~filesplit() { cout << "filesplit destructor" << endl; }

    void split()
    {
        for (int i = 0; i < m_filenum; i++)
        {
            float v = float(i+1)/m_filenum;
            onprocess(v);  // 发布
            sleep(1);
        }
        cout << "success split file " << m_filepath << endl;
        
    }
    //attach
    void addprocess(Iprocess* pro)   //可以添加观察者
    {
        m_iprocesslist.push_back(pro);
    }
    //dettach
    void delprocess(Iprocess* pro)
    {
        m_iprocesslist.remove(pro);
    }

protected:
    //notify
    void onprocess(float v)
    {
        auto it = m_iprocesslist.begin();
        while (it != m_iprocesslist.end())
        {
                (*it)->doprocess(v);
                it++;
        } 
    }
};

class progressbar {
public:
    void setval(float n){ v = n; cout << v << endl; }
private:
    float v;
};


class mainform : public Iprocess {  //观察者 concrete obervor
private:
    string path;
    int num;
    progressbar *probar;
public:
    mainform(string p, int n) : path(p), num(n) { 
        probar = new progressbar(); 
    }

    void button1(){

        filesplit splitter{path, num};
        splitter.addprocess(this);  //订阅通知
        splitter.split();
    }
    
    virtual void doprocess(float n) {
        probar->setval(n);
    }
    ~mainform() { delete probar; }
};


int main()
{
    mainform m{"mypath", 10};
    m.button1();
}



/*
如果将progressbar放入filesplit会有依赖性

*/