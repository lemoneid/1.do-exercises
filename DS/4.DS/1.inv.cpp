/*************************************************************************
	> File Name: oj-275.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月16日 星期二 21时41分08秒
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
using namespace std;
#define MAX_N 1000
int inv[MAX_N + 5] = {0};

int main() {
    inv[1] = 1;
    for (int i = 2; i < 7; ++i) {
        inv[i] = ((-(7 / 2) * inv[7 % i]) % 7 + 7) % 7;
    }
    return 0;
}
