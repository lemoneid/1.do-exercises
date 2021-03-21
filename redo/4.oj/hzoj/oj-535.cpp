/*************************************************************************
	> File Name: oj-535.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 10时30分42秒
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
using namespace std;
#define MAX_N 50
char matrix[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, cnt, sx, sy;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (matrix[xx][yy] == '.') {
            matrix[xx][yy] = '#';
            cnt++;
            dfs(xx, yy);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    if (matrix[sx][sy] != '@') {
        cout << 0 << endl;
        return 0;
    }
    cnt = 1;
    matrix[sx][sy] = '#';
    dfs(sx, sy);
    cout << cnt << endl;
    return 0;
}
