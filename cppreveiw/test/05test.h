#include <iostream>

using namespace std;


namespace l1 {
class Base {
public:
    virtual void read()
    {
        cout << "base read" << endl;
    }
    void write()
    {
        cout << "base wirte" << endl;
    }
    virtual void peek()
    {
        read();
    }
};


class Drive : public Base {
public:
    virtual void read()
    {
        cout << "derived read" << endl;
    }
};



namespace l2{
namespace l3{
        class DDrive : public Drive {
        public:
            virtual void read()
            {
                cout << "dderived read" << endl;
            }
            void poke()
            {
                Base::write();
            }
        };
}
}


}




