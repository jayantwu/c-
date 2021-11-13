class GamePlayer
{
    private:
        static const int num = 5;   // declare
        int scores[num];
};
const int GamePlayer::num;  //defination


class GamePlayer2
{
    private:
        enum { num = 5 };
        int scores[num];
};


// use inline not #define
//call f use the max of a and b
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

template <typename T>
inline void callWithMax(const T& a, const T& b)
{
    f(a > b ? a : b);   //f may  overload, so use T is good
}


int main()
{
    GamePlayer a;
    GamePlayer2 b;
}
