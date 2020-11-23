/*************************************************************************
	> File Name: oj-674.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 20时48分28秒
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
#define MAX_N 100
#define MAX_M 4500

int n, m, ans[MAX_N + 5][MAX_N + 5], mfront[MAX_N + 5], mback[MAX_N + 5];


int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        ans[a][b] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j] != 0x3f3f3f3f) {
                mback[i]++;
                mfront[j]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (mback[i] + mfront[i] == n - 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
