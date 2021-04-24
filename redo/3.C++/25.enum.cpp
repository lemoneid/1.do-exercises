/*************************************************************************
	> File Name: 25.enum.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月21日 星期三 21时08分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
using namespace std;

#define assert_static(expr) \
    do {enum {assert_static__ = 1 / (expr)}; } while (0)

enum FeatureSupports {
    One   = 0x00001,
    Two   = 0x00002,
    Three = 0x00004,
    Four  = 0x00008,
    MAX   = 0x00010,
};

enum class Enum : int {
    a, b, c, d
};

int main() {
    //检查枚举值的完备性
    assert_static((FeatureSupports::MAX - 1) == (FeatureSupports::One | FeatureSupports::Two | FeatureSupports::Three | FeatureSupports::Four));
    cout << (Enum::a == Enum::b) << endl;
    return 0;
}

