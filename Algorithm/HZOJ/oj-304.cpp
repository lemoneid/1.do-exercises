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
    int x, y, step;
};

int n, m;
char mmap[155][155];
int dir[8][2] = {
    1, 2, 1, -2,
    -1, 2, -1, -2,
    2, 1, 2, -1,
    -2, 1, -2, -1
};

int main() {
    queue <node> que;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                que.push({i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (mmap[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = '*';
                que.push({x, y, temp.step + 1});
            }
        }
    }
    return 0;
}
