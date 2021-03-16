/*************************************************************************
	> File Name: 36.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 10时59分43秒
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
#define MAX_N 1000000

bool is_val(int x, int base)  {
    if (base <= 1) return 0;
    int temp = x, sum = 0;
    while (temp) {
        sum = sum * base + temp % base;
        temp /= base;
    }
    return sum == x;
}

int main() {
    int sum = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (is_val(i, 10) && is_val(i, 2)) sum += i;
    }
    cout << sum << endl;

    return 0;
}
