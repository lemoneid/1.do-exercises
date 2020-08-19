/*************************************************************************
	> File Name: oj-405.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 18 Aug 2020 04:43:51 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

char mmap[3005][3005];
int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0};
int n, m, k, ans[3005][3005];

queue <node> que;

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m) {
            continue;
        }
        if (ans[xx][yy] == 0 && mmap[xx][yy] != mmap[x][y]) {
            ans[xx][yy] = 1;
            que.push((node){xx, yy});
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> (&mmap[i][1]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ans[i][j] == 0) {
                que.push((node){i, j});
                ans[i][j] = 1;
                func(i, j);
                //do
                int tmp = que.size();
                while (!que.empty()) {
                    node t = que.front();
                    que.pop();
                    ans[t.x][t.y] = tmp;
                }
            }
        }
    }

    int x, y;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }

    return 0;
}
