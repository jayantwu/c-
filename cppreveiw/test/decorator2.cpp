#include<iostream>

using namespace std;


//业务操作
class Stream{

public:
    virtual void Read()=0;
    virtual void Seek()=0;
    virtual void Write()=0;
    
    virtual ~Stream(){}
};

//主体类
class FileStream: public Stream{
public:
    virtual void Read(){
        //读文件流
        cout << "读文件流" << endl;
    }
    virtual void Seek(){
        //定位文件流
        cout << "定位文件流" << endl;
    }
    virtual void Write(){
        //写文件流
        cout << "写文件流" << endl;
    }

};


//扩展操作
class CryptoStream: public Stream {
    
    Stream* stream;//...

public:
    CryptoStream(Stream* stm):stream(stm){
    
    }
    
    
    virtual void Read(){
       
        //额外的加密操作...
        cout << "加密..." << endl;
        stream->Read();//读文件流
    }
    virtual void Seek(){
        //额外的加密操作...
        cout << "加密..." << endl;
        stream->Seek();//定位文件流
        //额外的加密操作...
    }
    virtual void Write(){
        //额外的加密操作...
        cout << "加密..." << endl;
        stream->Write();//写文件流
        //额外的加密操作...
    }
};



class BufferedStream : public Stream {
    
    Stream* stream;//...
    
public:
    BufferedStream(Stream* stm):stream(stm){
        
    }
    virtual void Read(){
       
        //额外的缓存操作...
        cout << "缓存..." << endl;
        stream->Read();//读文件流
    }
    virtual void Seek(){
        //额外的缓存操作...
        cout << "缓存..." << endl;
        stream->Seek();//定位文件流
        //额外的缓存操作...
    }
    virtual void Write(){
        //额外的缓存操作...
        cout << "缓存..." << endl;
        stream->Write();//写文件流
        //额外的缓存操作...
    }
};





int main() {

    //运行时装配
    FileStream* s1=new FileStream();
    CryptoStream* s2=new CryptoStream(s1);
    
    BufferedStream* s3=new BufferedStream(s1);
    
    BufferedStream* s4=new BufferedStream(s2);

    CryptoStream* s5 = new CryptoStream(s3);
    
    s1->Read();
    cout << "*********" << endl;
    s2->Read();
    cout << "*********" << endl;

    s3->Read();
    cout << "*********" << endl;
    s4->Read();

    cout << "*********" << endl;
    s5->Read();

    return 0;

}

/*
output:

读文件流
*********
加密...
读文件流
*********
缓存...
读文件流
*********
缓存...
加密...
读文件流
*********
加密...
缓存...
读文件流




*/