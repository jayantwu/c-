// g++ test_gtest1.cpp /usr/local/lib/libgtest.a -lpthread -std=c++11

#include <iostream>
#include <gtest/gtest.h>

// 待测函数
int fun(int a) {
  return a + 1;
}

int add(int a, int b) {
    return a + b;
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
    EXPECT_EQ(3, add(2, 2));  // failed
}


class mytestfun: public ::testing::Test {
    protected:
        mytestfun(){   //constructor no need
            
        }

        int add(int a, int b) {
            return a + b;
        }
        int minus(int a, int b){
            return a - b;
        }

};

TEST_F(mytestfun, testadd)
{
    EXPECT_EQ(4, add(2, 2));  // ok
}


TEST_F(mytestfun, testminus)
{
    EXPECT_EQ(0, minus(2, 2));  // ok
}

int main(int argc, char **argv) {
  // 规定的 2 行代码
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}