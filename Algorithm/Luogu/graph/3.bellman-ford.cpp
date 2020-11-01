/*************************************************************************
	> File Name: 3.bellman-ford.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 18时37分36秒
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

int n, m, s, edg[50005][3], ans[10005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        cin >> edg[i][0] >> edg[i][1] >> edg[i][2];
    }
    ans[s] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[edg[j][1]] = min(ans[edg[j][1]], ans[edg[j][0]] + edg[j][2]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        if (ans[i] == 0x3F3F3F3F) cout << 0x7fffffff;
        else cout << ans[i];
    }
    cout << endl;
    return 0;
}
