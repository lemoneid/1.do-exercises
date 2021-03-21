/*************************************************************************
	> File Name: oj-529.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 13时47分06秒
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
#include <queue>
#include <map>
using namespace std;
#define MAX_N 128
char matrix[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5];
int mark[MAX_N + 5][MAX_N + 5];
int n, m, s1, e1, s2, e2;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0,
                1, 1, 1, -1, -1, 1, -1, -1};

struct Data {
    int x, y, step;
};

void init(int sx, int sy) {
    mark[sx][sy] = 1;
    int x, y;
    for (int i = 0; i < 8; i++) {
        x = sx, y = sy;
        while (1) {
            x += dir[i][0];
            y += dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m) break;
            if (matrix[x][y] == 'X') break;
            mark[x][y] = 1;
        }
    }
    return ;
}

int solve() {
    cin >> s2 >> e2 >> s1 >> e1;
    if (!s1) return 0;
    memset(mark, 0, sizeof(mark));
    memset(check, 0, sizeof(check));
    init(s2, e2);
    if (mark[s1][e1]) {
        cout << 0 << endl;
        return 1;
    }
    queue<Data> que;
    que.push({s1, e1, 0});
    check[s1][e1] = 1;

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (matrix[x][y] != 'O') continue;
            if (check[x][y]) continue;
            if (mark[x][y]) {
                cout << cur.step + 1 << endl;
                return 1;
            } 
            que.push({x, y, cur.step + 1});
            check[x][y] = 1;
        }
    }
    cout << "Impossible!" << endl;
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i] + 1;
    }
    while (solve()) ; 
    return 0;
}
