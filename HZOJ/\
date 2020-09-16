/*************************************************************************
	> File Name: oj-81.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Mon 31 Aug 2020 05:07:21 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step, phone;
};

int n, m, sx, sy, tx, ty, cnt = 0, ans = 0x7fffffff;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[2005][2005];
int check[2][2005][2005];

int main() {
    queue <node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push({i, j, 0, 0});
                check[0][i][j] = 1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == 'T' && temp.phone == 1) {
                cout << temp.step  + 1<< endl;
                return 0;
            }
            if (mmap[xx][yy] == 'P' && check[1][xx][yy] == 0) {
                check[1][xx][yy] = 1;
                que.push({xx, yy, temp.step + 1, 1});
            }
            if (mmap[xx][yy] == '.' ||
                mmap[xx][yy] == 'P' ||
                mmap[xx][yy] == 'S' ||
                mmap[xx][yy] == 'T'
               ) {
                   if (check[0][xx][yy] == 0 && temp.phone == 0) {
                       check[0][xx][yy] = 1;
                       que.push({xx, yy, temp.step + 1, 0});
                   } else if (temp.phone == 1 && check[1][xx][yy] == 0) {
                       check[1][xx][yy] = 1;
                       que.push({xx, yy, temp.step + 1, 1});
                   }
               }
        }
    }
    cout << ans << endl;
    return 0;
}
