/*************************************************************************
	> File Name: oj-529.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Mon 31 Aug 2020 02:13:18 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int n, m, sx, sy, ex, ey;
char mmap[150][150];
int flag[150][150];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
    int x, y, step;
};

int handle(node temp) {
    int xx = ex - temp.x;
    int yy = ey - temp.y;
    if (!(abs(xx) == abs(yy) || !xx || !yy)) return 0;
    if (xx > 0) {
        xx = 1;
    } else if (xx < 0){
        xx = -1;
    }
    if (yy > 0) {
        yy = 1;
    } else if (yy < 0) {
        yy = -1;
    }
    int x = temp.x;
    int y = temp.y;

    while (mmap[x][y] == 'O') {
        if (x == ex && y == ey) {
            return 1;
        }
        x += xx;
        y += yy;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    queue <node> que;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    
    while ((cin >> ex >> ey >> sx >> sy) && sx && sy && ex && ey) {
        int res = 0;
        memset(flag, 0, sizeof(flag));
        while (!que.empty()) {
            que.pop();
        }
        que.push({sx, sy, 0});
        flag[sx][sy] = 1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            res = handle(temp);
            if (res == 1) {
                cout << temp.step << endl;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int xx = temp.x + dir[i][0];
                int yy = temp.y + dir[i][1];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (flag[xx][yy] || mmap[xx][yy] != 'O') continue;
                que.push({xx, yy, temp.step + 1});
                flag[xx][yy] = 1;
            }

        }
        if (res == 0) {
            cout << "Impossible!" << endl;
        }
    }
    return 0;
}
