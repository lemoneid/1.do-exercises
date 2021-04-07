/*************************************************************************
	> File Name: oj-533.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 20时45分01秒
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
const int MAX_N = 100;
int matrix[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct Data {
    int x, y, cost, last;
};

#ifdef _D
#define DBG(frm, args...) printf(frm, ##args);
#else
#define DBG(frm, args...)
#endif

int main() {
    memset(check, 0x7f, sizeof(check));
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        matrix[u][v] = w + 1;
    }
    queue<Data> que;
    que.push({1, 1, 0, matrix[1][1]});
    int flag = 0;
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        if (cur.x == n && cur.y == n) {
            check[n][n] = min(check[n][n], cur.cost);
            DBG("%d\n", check[n][n]);
            flag = 1;
            continue;
        }
        if (check[cur.x][cur.y] <= cur.cost) continue;
        check[cur.x][cur.y] = cur.cost;
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > n) continue;
            if (matrix[x][y] == 0 && (cur.last & 4)) continue;
            if (matrix[x][y] == 0) {
                que.push({x, y, cur.cost + 2 + !!(cur.last != 1), 5});
                que.push({x, y, cur.cost + 2 + !!(cur.last != 2), 6});
            } else {
                int val = (matrix[x][y] != (cur.last & 3));
                que.push({x, y, cur.cost + val, matrix[x][y]});
                if (x == n && y == n) {
                   DBG("x = %d, y = %d, col = %d, cost = %d, val = %d\n", cur.x, cur.y, cur.last, cur.cost, val); 
                }
            }
        }
    }
    cout << (flag ? check[n][n] : -1) << endl;
    return 0;
}
