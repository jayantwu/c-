#include <iostream>
#include <vector>

using namespace std;


class point{
    public:
        point()=default;
        point(int a, int b):x(a), y(b){}
        void setx(int newval){x = newval;}
        void sety(int newval){y = newval;}

    private:
        int x;
        int y;
};


struct recdata{
    point ul;
    point lr;
};


class rectangle{
    public:
        rectangle(const point & p1, const point & p2)
        {
            pdata = shared_ptr<recdata>(new recdata);
            pdata->ul = p1;
            pdata->lr = p2;
        }
        const point & upperleft() const { return pdata->ul;}
        const point & lowerright()const { return pdata->lr;}

    private:
        shared_ptr<recdata> pdata;
};


int main()
{
    point p1(1, 2);
    point p2(3, 4);
    rectangle rect(p1, p2);
    //rect.upperleft().setx(3);  
}



