/*************************************************************************
	> File Name: oj-354.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月28日 星期三 19时01分50秒
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
#include <set>
using namespace std;
#define MAX_N 1000
#define MAX_M 100000

int f[MAX_M + 5];
int val[MAX_N + 5], cnt = 0;
int a[MAX_N + 5], b[MAX_N + 5];

int solve() {
    memset(f, 0, sizeof(f));
    cnt = 0;
    int n, m;
    cin >> n >> m;
    if (n == 0 || m == 0) return 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= b[i]; j <<= 1) {
            val[cnt++] = a[i] * j; 
            b[i] -= j;
        }
        if (b[i] != 0) val[cnt++] = a[i] * b[i];
    }
    f[0] = 1;
    for (int i = 0; i < cnt; ++i) {
        for (int j = m; j >= val[i]; j--) {
            f[j] += f[j - val[i]];
        }
    }
    int ans = 0;
    for (int i  = 1; i <= m; ++i) ans += (f[i] != 0);
    cout << ans << endl;
    return 1;
}

int main() {
    while (solve());
    return 0;
}
