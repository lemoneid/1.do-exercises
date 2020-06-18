/*************************************************************************
	> File Name: main.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 15时29分32秒
 ************************************************************************/

#include <cstdio>
#include "test.h"

int add(int a, int b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(3, 5), 8);
    EXPECT_EQ(add(3, 1), 7);
}

TEST(test2, add) {
    EXPECT_EQ(add(2, 5), 8);
    EXPECT_EQ(add(1, 5), 8);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
