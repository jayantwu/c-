#include<iostream>
#include<vector>
using namespace std;

class testA
{
    string name;
    int a;
    vector<int*> v;
    public:
        testA(const string &s, const vector<int*> & int_v)
        : name(s)
        {
            a = *(int_v[0]);
        }

        testA(const string & s)
        : testA(s, vector<int*>({new int(55)}))
        {

        }

        void show()
        {
            cout << name << ": " << a << endl;
        }

        int &operator() ()
        {
            return a;
        }


};

class origin_B {
    public:
        origin_B(string n, string d, int b) : 
            name(n), desc(d), _b(b) {}
        virtual ~origin_B() = default;

    private:
        string name;
        string desc;
        int _b;
};

class testB {
public:
    testB(string s, int n):a(s), b(n) {}
    virtual void show() {
        cout << a << "***" << b << endl;
    }
private:
    string a;
    int    b;
};
//假设场景：testbc 是 依赖与testB的，所以可以以testB作为参数
//比如： 一个学生，属于一个班级，一个班级是属于一个学校的，这里没有继承关系，但是有依赖关系，包含关系
//比如，一个国家，省， 市之间的关系
//比如下面testbc描述了一个市， ctor的参数代表他所属的省
class testbc {   
public:
    testbc(testB & tb) : tb(tb) {};
    ~testbc()=default;
    void set(int n) { val = n; cout << "val set to " << n << endl; }
    void showv() { cout << "the val is " << val << endl; }
private:
    testB tb;
    int val;
};
//
//如果testC看成一个省， 他需要创建很多的市 create（）
//那么在构造这个省的时候，同时需要创建他所拥有的市 new， 这个时候就用到了 this！
class testC : public testB {
public:
    testC(string s, int n, double d) : testB(s, n), c(d) {} 
    void show()
    {
        testB::show();
        cout << c << endl;
    }
    void create() {
        ptr_tbc = shared_ptr<testbc> {new testbc { *this }};  // 用testC本身作为参数构造testbc
    }
    shared_ptr<testbc> & getptr() {
        return ptr_tbc;
    }
private:
    double c;
    shared_ptr<testbc> ptr_tbc;
};



int main()
{
    testA a("wujiayang");
    a.show();
    testA b = testA("frank");
    b.show();

    cout << "use () to return a: " << a() << endl;  // use () to return a: 55
    
    vector<int*> vv = vector<int*> ({new int(55), new int(66)}); // 2 element
    for (auto it : vv)
        cout << "vv= "<< *it << endl;


    vector<int> v = vector<int>({1, 2, 3});
    for (auto i : v)
        cout << "v=" << i << endl;

    ////////
    //test class relationship
    testC tc("mytest", 0, 0.0);
    tc.create();
    tc.getptr()->set(5);
    tc.getptr()->showv();
}