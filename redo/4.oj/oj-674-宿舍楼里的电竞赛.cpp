/*************************************************************************
	> File Name: oj-674-宿舍楼里的电竞赛.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 21时24分21秒
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
#define MAX_N 100

int n, m, ans[MAX_N + 5][MAX_N + 5];
int l[MAX_N + 5], r[MAX_N + 5];

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ans[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 0x3f3f3f3f) continue;
            l[i]++;
            r[j]++;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] + r[i] == n - 1) res++;
    }
    cout << res << endl;
    return 0;
}
