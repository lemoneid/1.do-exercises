/*************************************************************************
	> File Name: oj-527-飞跃原野.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 20时04分46秒
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
char matrix[MAX_N + 5][MAX_N + 5];
bool check[MAX_N + 5][MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct Data {
    int x, y, d, time;
};

int main() {
    memset(check, false, sizeof(check));
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) cin >> matrix[i] + 1;
    queue<Data> que;
    que.push({1, 1, d, 0});
    for (int i = 0; i <= d; i++) {
        check[1][1][i] = true;
    }
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (x == n && y == m) {
                cout << cur.time  + 1 << endl;
                return 0;
            }
            if (matrix[x][y] == 'P' && !check[x][y][cur.d]) {
                check[x][y][cur.d] = true;
                que.push({x, y, cur.d, cur.time + 1});
            }
            //if (matrix[x][y] != 'L') continue;
            for (int j = 2; j <= cur.d; j++) {
                x = cur.x + dir[i][0] * j;
                y = cur.y + dir[i][1] * j;
                if (matrix[x][y] == 0) break;
                int left = cur.d - j;
                if (x == n && y == m) {
                    cout << cur.time  + 1 << endl;
                    return 0;
                }
                if (matrix[x][y] == 'P' && !check[x][y][left]) {
                    check[x][y][left] = true;
                    que.push({x, y, left, cur.time + 1});
                }
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
