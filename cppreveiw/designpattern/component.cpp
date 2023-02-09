#include <list>
#include <iostream>
#include <string>

using namespace std;

class component {
    public :
        virtual void process() = 0;
        virtual ~component(){};

};

class composite : public component 
{
    string name;
    list<component*> elems;
    public:
        composite(string s) : name(s) {}
        virtual void process() {
            cout << name << endl;
            for (auto elem : elems) {
                elem->process();
            }
        }
        void add(component * ele) {
            elems.push_back(ele);
        }
        void remove(component * ele) {
            elems.remove(ele);
        }
        virtual ~composite(){}; 
};


class leaf : public component {
    string name;
    public:
        leaf(string s) : name(s) {
        }
        virtual void process() {
            cout << name << endl;
        }
        virtual ~leaf(){};
};


int main()
{
    composite root("root");
    composite treenode1("treenode1");
    composite treenode2("treenode2");
    leaf leaf1("leaf1");
    leaf leaf2("leaf2");
    leaf leaf3("leaf3");
    root.add(&treenode1);
    root.add(&treenode2);
    treenode1.add(&leaf1);
    treenode2.add(&leaf2);
    treenode2.add(&leaf3);

    root.process();

    return 0;
}



/*
output:

root
treenode1
leaf1
treenode2
leaf2
leaf3
*/