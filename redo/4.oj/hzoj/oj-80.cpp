/*************************************************************************
	> File Name: oj-80.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 20时04分30秒
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
#define MAX_N 500
int n, m;
char grid[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct Data {
    int x, y, step;
};

int main() {
    cin >> n >> m;
    queue<Data> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                que.push({i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (grid[x][y] == 'g') {
                cout << cur.step + 1 << endl;
                return 0;
            }
            if (grid[x][y] == '.') {
                que.push({x, y, cur.step + 1});
                grid[x][y] = '#';
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
