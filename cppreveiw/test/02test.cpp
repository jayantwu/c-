#include <iostream>
using namespace std;
enum class color {red, yellow, green, blue};  //scope enum

ostream& operator<<(ostream& os, color c)
{
    switch(c)
    {
        case color::red   : os << "red";    break;
        case color::yellow: os << "yellow"; break;
        case color::green : os << "green";  break;
        case color::blue  : os << "blue";   break;
        default    : os.setstate(ios_base::failbit);
    }
    return os;
}
int main()
{
    enum state : uint8_t
    {
        admindown,   // if admindown=254, then init will be 256, error
        down,
        init,
        up
    }s;

    //enum class color {red, blue};  //scope enum

    enum class color2 {red, pink};
    color c2 = color::red;
    //cout << color::red << endl;
    cout << c2 << endl;

    int res(5);    // res = 5
    cout << res << endl;
    state packeta = admindown;
    state packetb = down;
    if (packeta != up)
        cout << "packet A is not up" << endl;

    if (packetb == down)
        cout << "packet B is down" << endl;


}