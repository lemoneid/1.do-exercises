/*************************************************************************
	> File Name: oj-529-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 20时31分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, cx, cy, ex, ey;
int check[150][150];
char mmap[150][150];
int dir[8][2] = {0 , 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

void bfs() {
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 8; ++i) {
        for (int j = 1; 1; j++) {
            int x = ex + dir[i][0] * j;
            int y = ey + dir[i][1] * j;
            if (x < 1 || y < 1 || x > n || y > m) break;
            if (mmap[x][y] == 'O') {
                check[x][y] = 1;
                continue;
            }
            break;
        }
    }
    check[ex][ey] = 1;
    if (check[cx][cy] == 1) {
        cout << 0 << endl;
        return ;
    }
    queue <node> que;
    que.push((node){cx, cy, 0});
    check[cx][cy] += 2;
    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (check[x][y] == 1) {
                cout << tmp.step + 1 << endl;
                return ;
            }
            if (x < 1 || y < 1 || x > n || y > m || check[x][y] == 2) {
                continue;
            }
            if (mmap[x][y] == 'O' && check[x][y] != 2) {
                check[x][y] = 2;
                que.push((node){x, y, tmp.step + 1});
            }
        }
    }
    cout << "Impossible!" << endl;
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    while (cin >> ex >> ey >> cx >> cy && cx && cy && ex && ey) {
        bfs();
    }
    return 0;
}
