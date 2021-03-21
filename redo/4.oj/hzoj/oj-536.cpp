/*************************************************************************
	> File Name: oj-536.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 10时42分53秒
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
#define MAX_N 100
char matrix[MAX_N + 5][MAX_N + 5];
int n, m, ans, cnt;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (matrix[xx][yy] == '1') {
            matrix[xx][yy] = '0';
            cnt++;
            dfs(xx, yy);
        }
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] == '1') {
                matrix[i][j] = '0';
                cnt = 1;
                dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
