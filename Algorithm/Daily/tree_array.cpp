/*************************************************************************
	> File Name: tree_array.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 23时31分25秒
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
int c[MAX_N + 5];
#define lowbit(x) (x & -x)

int add(int x, int val, int n) {
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
}


int main() {

    return 0;
}
