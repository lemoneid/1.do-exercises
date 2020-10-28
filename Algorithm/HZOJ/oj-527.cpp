/*************************************************************************
	> File Name: oj-527.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 01 Sep 2020 06:08:19 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step, left;
};

int n, m, d;
char mmap[105][105];
int check[105][105][105];
int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    queue <node> que;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    
    que.push({1, 1, 0, d});
    for (int i = 0; i <= d; ++i) {
        check[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && !check[x][y][temp.left]) {
                check[x][y][temp.left] = 1;
                que.push({x, y, temp.step + 1, temp.left});
            }
            for (int j = 2; j <= temp.left; ++j) {
                int xx = temp.x + j * dir[i][0];
                int yy = temp.y + j * dir[i][1];
                if (mmap[xx][yy] == 0) break;
                if (xx == n && yy == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                int left = temp.left - j;
                if (mmap[xx][yy] == 'P' && !check[xx][yy][left]) {
                    check[xx][yy][left] = 1;
                    que.push({xx, yy, temp.step + 1, left});
                }
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}
