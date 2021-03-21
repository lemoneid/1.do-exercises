/*************************************************************************
	> File Name: oj-305.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 13时49分38秒
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
#include <queue>
using namespace std;
#define MAX_N 100
char g[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

struct Data {
    int x, y, step;
};

int main() {
    int n, m, sx, sy;
    cin >> m >> n >> sy >> sx;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    queue<Data> que;
    que.push({n - sx + 1, sy, 0});
    g[n - sx + 1][sy] = 'M';
    int ans = 1;
    while (!que.empty()) {
        Data cur = que.front();
        ans = max(ans, cur.step);
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (g[x][y] == '.') {
                g[x][y] = 'M';
                que.push({x, y, cur.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
