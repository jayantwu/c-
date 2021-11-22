// g++ test_gtest1.cpp /usr/local/lib/libgtest.a -lpthread -std=c++11

#include <iostream>
#include <gtest/gtest.h>
using namespace std;



// 待测函数
int fun(int a) {
  return a + 1;
}

int add(int a, int b) {
    return a + b;
}

bool isEven(int n)
{
    if ((n % 2) == 0)
        return true;
    else
        return false;
}

testing::AssertionResult testisEven(int n)
{
    if (isEven(n))
        return testing::AssertionSuccess() << n << " is even";
    else
        return testing::AssertionFailure() << n << " is odd";
}

TEST(Funtest, isEven)
{
    EXPECT_TRUE(testisEven(5));
}

TEST(Funtest, isEven2)
{
    int a = 8;
    EXPECT_PRED1(testisEven, a);
}

// 单元测试
TEST(FunTest, HandlesZeroInput) {
  EXPECT_EQ(1, fun(0));  // ok
}

TEST(FunTest, HandlesFirstInput) {
    EXPECT_EQ(2, fun(1));  // ok
}

TEST(AddTest, HandlesAdd1and2) {
    EXPECT_EQ(3, add(1, 2)); // ok
}

TEST(AddTest, HandlesAdd2and2) {
    GTEST_SKIP() << "Skipping single test";
    EXPECT_EQ(3, add(2, 2));  // failed
}


class mytestfun: public ::testing::Test {
    protected:
        void SetUp() override
        {
            ptra = shared_ptr<int>{new int(5)};
            ptrb = shared_ptr<int>(new int(6));
            cout << " set up " << endl;
        }

        void TearDown() override
        {
            //delete ptra;
            //delete ptrb;
            cout << "tear down" << endl;
        }

        int geta()
        {
            return *ptra;
        }

        int getb()
        {
            return *ptrb;
        }

        int add(int a, int b) {
            return a + b;
        }
        int minus(int a, int b){
            return a - b;
        }

        //int * ptra;
        //int * ptrb;
        shared_ptr<int> ptra;
        shared_ptr<int> ptrb;

};

TEST_F(mytestfun, testadd)
{
    EXPECT_EQ(4, add(2, 2));  // ok
}


TEST_F(mytestfun, testminus)
{
    EXPECT_EQ(0, minus(2, 2));  // ok
}

TEST_F(mytestfun, geta)
{
    EXPECT_EQ(5, geta());
}

TEST_F(mytestfun, getb)
{
    EXPECT_EQ(6, getb());
}

int main(int argc, char **argv) {
  // 规定的 2 行代码
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}