/*************************************************************************
	> File Name: main.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 15时29分32秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include "haizei/test.h"
using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(test1, add) {
    EXPECT_EQ(add(3, 5), 8);
    EXPECT_EQ(add(3, 1), 7);
    EXPECT_NE(add(22, 1), 71);
    EXPECT_LT(add(12, 1), 71);
    EXPECT_GT(add(4, 1), 5);
    EXPECT_LE(add(56, 1), 57);
    EXPECT_GE(add(23, 1), 712);
}

TEST(test2, add) {
    EXPECT_EQ(add(2, 5), 7);
    EXPECT_EQ(add(1, 5), 6);
    EXPECT_NE(add(1, 5), 9);
    EXPECT_LT(add(1, 5), 9);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
