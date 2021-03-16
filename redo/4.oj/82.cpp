/*************************************************************************
	> File Name: 82.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 20时49分30秒
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
int h[MAX_N + 5];
long long n, m;

int calc(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i] - x > 0 ? h[i] - x : 0;
        if (sum >= m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    int l = 0, r = 0, mid;
    for (int i = 0; i < n; i++) cin >> h[i], r = max(r, h[i]);
    while (l < r)  {
        mid = (l + r + 1) >> 1;
        if (calc(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
