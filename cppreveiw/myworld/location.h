#ifndef _LOCATION_H_
#define _LOCATION_H_


class Location
{
    private:
        int x;
        int y;

    public:
        Location(int a = 0, int b = 0);
        Location(const Location & l)
        {
            x = l.x;
            y = l.y;
        }
        ~Location();
        void showlocation();
        int getx();
        int gety();
        void addmove(int a, int b);
};



#endif