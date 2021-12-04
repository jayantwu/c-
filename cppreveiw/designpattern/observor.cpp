#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Iprocess {   // this is important   //观察者
public:
    virtual void doprocess(float n)=0;
    virtual ~Iprocess() {}
};


class filesplit {  //这是一个稳定的类   // 目标
private:
    string m_filepath;
    int m_filenum;
    Iprocess * m_iprocess;  
public:
    filesplit(const string filepath, int filenum, Iprocess * iprocess):
    m_filepath(filepath),
    m_filenum(filenum),
    m_iprocess(iprocess)
    {}
    ~filesplit() { cout << "filesplit destructor" << endl; }

    void split()
    {
        for (int i = 0; i < m_filenum; i++)
        {
            if (m_iprocess != nullptr)
                m_iprocess->doprocess(float(i+1)/m_filenum);
            sleep(1);
        }
        cout << "success split file " << m_filepath << endl;
        
    }
};

class progressbar {
public:
    void setval(float n){ v = n; cout << v << endl; }
private:
    float v;
};

class mainform : public Iprocess {  //观察者
private:
    string path;
    int num;
    progressbar *probar;
public:
    mainform(string p, int n) : path(p), num(n) { 
        probar = new progressbar(); 
    }
    filesplit splitter{path, num, this};
    virtual void doprocess(float n) {
        probar->setval(n);
    }
    ~mainform() { delete probar; }
};


int main()
{
    mainform m{"mypath", 10};
    m.splitter.split();
}



/*
如果将progressbar放入filesplit会有依赖性

*/