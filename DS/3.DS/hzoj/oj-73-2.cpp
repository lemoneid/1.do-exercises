/*************************************************************************
	> File Name: oj-73-2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月28日 星期四 17时47分23秒
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
char g[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
void dfs(int x, int y) {
    g[x][y] = 'X';
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx > n + 1 || yy > m + 1) continue;
        if (g[xx][yy] != 'X') {
            g[xx][yy] = 'X';
            dfs(xx, yy);
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> &g[i][1];
    dfs(0, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += g[i][j] == 'O';
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << g[i][j];
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}
