/*************************************************************************
	> File Name: 304.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 13时38分08秒
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
#define MAX_N 150
char g[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {-2, 1, -2, -1, 
                2, 1, 2, -1, 
                -1, 2, -1, -2,
                1, 2, 1, -2};

struct Data {
    int x, y, step;
};
int n, m;

int main() {
    cin >> m >> n;
    queue<Data> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'K') {
                que.push({i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (g[x][y] == 'H') {
                cout << cur.step + 1 << endl;
                return 0;
            }
            if (g[x][y] == '.') {
                que.push({x, y, cur.step + 1});
                g[x][y] = '*';
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
