/*************************************************************************
	> File Name: oj-81.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 20时27分21秒
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
#define MAX_N 2000
int n, m;
char  grid[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct Data {
    int x, y, step, flag;
};

int main() {
    cin >> n >> m;
    queue<Data> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                que.push({i, j, 0, 0});
                check[i][j] |= 1;
            }
        }
    }
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (cur.flag == 1 && grid[x][y] == 'T') {
                cout << cur.step + 1 << endl;
                return 0;
            }
            if (grid[x][y] == 'P' && (check[x][y] & 2) == 0) {
                check[x][y] |= 2;
                que.push({x, y, cur.step + 1, 1});
            }
            if (grid[x][y] == 'S' 
                || grid[x][y] == '.' 
                || grid[x][y] == 'T'
                || grid[x][y] == 'P') {
                    if (cur.flag == 0 && (check[x][y] & 1) == 0) {
                        check[x][y] |= 1;
                        que.push({x, y, cur.step + 1, 0});
                    } else if (cur.flag == 1 && (check[x][y] & 2) == 0){
                        check[x][y] |= 2;
                        que.push({x, y, cur.step + 1, 1});
                    }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
