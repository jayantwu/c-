class A
{
    private:
        mutable int a;  // a can be modified in const member function
        int b;
    public:
        int get()const{
            a = 1;
            //b = 2;  //because of bitwise constness, b cannt be modified
            return a;
        }
};

int main()
{
    A aa;
    aa.get();
}