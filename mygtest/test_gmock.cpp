#include <gtest/gtest.h>
#include "demo.h"
#include <gmock/gmock.h>

class MockParent : public Parent {
  public:
//!  MOCK_METHOD(ReturnType, MethodName, (Args...), (Specs...));
    MOCK_METHOD(int, getNum, (), (const));    //! 由于 getNum() 是 const 成员函数，所以要使用 MOCK_CONST_METHODx
    MOCK_METHOD(void, setResult, (int), (override));
    MOCK_METHOD(void, print, (const string &), (override));
    MOCK_METHOD(int, calc, (int, double), (override));
};

using ::testing::Return;
using ::testing::_;

TEST(demo, 1) {
    MockParent p;
    Target t(&p);

    //! 设置 p.getNum() 方法的形为
    EXPECT_CALL(p, getNum())
        .Times(2)    //! 期望被调两次
        .WillOnce(Return(2))   //! 第一次返回值为2
        .WillOnce(Return(10)); //! 第二次返回值为10

    //! 设置 p.setResult(), 参数为2的调用形为
    EXPECT_CALL(p, setResult(2))
        .Times(1);

    EXPECT_CALL(p, print(_))  //! 表示任意的参数，其中 _ 就是 ::testing::_ ，如果冲突要注意
        .Times(2);

    EXPECT_EQ(t.doThis(), 10);
}

TEST(demo, 2) {
    MockParent p;
    Target t(&p);

    EXPECT_CALL(p, calc(1, 2.2))
        .Times(1)
        .WillOnce(Return(3));

    EXPECT_EQ(t.doThat(), 3);
}

/*
Running main() from gmock_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from demo
[ RUN      ] demo.1
2
[       OK ] demo.1 (0 ms)
[ RUN      ] demo.2
[       OK ] demo.2 (0 ms)
[----------] 2 tests from demo (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
*/