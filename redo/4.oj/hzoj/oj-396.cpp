/*************************************************************************
	> File Name: oj-396.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 11时15分21秒
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
#define MAX_N 30
int matrix[MAX_N + 5][MAX_N + 5];
int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || xx > n + 1 || yy < 0 || yy > m + 1) {
            continue;
        }
        if (matrix[xx][yy] == 0) {
            matrix[xx][yy] = 3;
            dfs(xx, yy);
        }
    }
}

int main() {
    cin >> n;
    m = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    matrix[0][0] = 3;
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            j > 1 && cout << " ";
            if (matrix[i][j] == 3) cout << 0;
            else if (matrix[i][j] == 1) cout << 1;
            else cout << 2;
        }
        cout << endl;
    }
    return 0;
}
