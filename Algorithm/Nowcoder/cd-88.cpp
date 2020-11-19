/*************************************************************************
	> File Name: cd-88.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 18时12分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 1000000
long long dp[MAX_N + 5];

int main() {
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    long long step = 0;
    for (; dp[k] < n; ++step) {
        for (int i = k; i > 0; i--) {
            dp[i] += dp[i - 1] + 1;
        }
    }
    cout << step << endl;
    return 0;
}
