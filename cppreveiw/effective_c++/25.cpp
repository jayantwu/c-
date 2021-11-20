#include <iostream>
#include <algorithm>  // for std::swap
#include <vector> 
class Widgetpimpl
{
    public:
        Widgetpimpl(int x, int y, int z, std::vector<double>& vv):
        a(x), b(y), c(z), v(vv){}

        int geta(){ return a;}
        int getb(){ return b;}
        int getc(){ return c;}
        std::vector<double>& getv()
        {
            return v;
        }
        

    private:
        int a, b, c;
        std::vector<double> v;
};

class Widget
{
    public:
        
        Widget()=default;
        Widget(Widgetpimpl* wp): pImpl(wp){}

        Widget(const Widget &rhs);
        Widget & operator=(const Widget& rhs)
        {
            if (this == &rhs)
                return *this;
            delete pImpl;
            pImpl = new Widgetpimpl(*rhs.pImpl);
            return *this;
        }
        
        void swap(Widget& other)
        {
            using std::swap;
            swap(pImpl, other.pImpl);  // swap pointer, 这里other.pImpl 貌似没有问题哎
            std::cout << "swap end " << std::endl;

        }
        Widgetpimpl* getptr()
        {
            return pImpl;
        }



    private:
        Widgetpimpl* pImpl;
};


namespace std
{
    template<>
    void swap<Widget>(Widget & a, Widget& b)
    {
        a.swap(b);
    }
}



int main()
{
    std::vector<double> v1 = {1.2, 1.3, 1.4};
    std::vector<double> v2 = {2.2, 2.3, 2.4};
    Widgetpimpl wp1(1, 2, 3, v1);
    Widgetpimpl wp2(4, 5, 6, v2);
    //Widgetpimpl *pwp = new Widgetpimpl(1, 2, 3, v1);
    Widget w1(&wp1);

    Widget w2(&wp2);

    //Widget w3(pwp);
    std::swap(w1, w2);
    std::cout << w1.getptr()->getv()[0] << std::endl;
    std::cout << w2.getptr()->getv()[0] << std::endl;
}


