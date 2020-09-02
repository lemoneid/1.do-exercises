/*************************************************************************
	> File Name: oj-398.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 30 Aug 2020 08:26:16 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

int n, m, sx, sy;
int mmap[405][405];
int dir[8][2] = {
    1, 2, 1, -2,
    -1, 2, -1, -2,
    2, 1, 2, -1,
    -2, 1, -2, -1
};

int main() {
    queue <node> que;
    cin >> n >> m >> sx >> sy;
    que.push({sx, sy});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (mmap[x][y]) continue;
            mmap[x][y] = mmap[temp.x][temp.y] + 1;
            que.push({x, y});
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            j != 1 && cout << " ";
            if (i == sx && j == sy) {
                cout << 0;
                continue;
            }
            if (mmap[i][j]) {
                cout << mmap[i][j];
            } else {
                cout << -1;
            }
        }
        cout << endl;
    }

    return 0;
}
