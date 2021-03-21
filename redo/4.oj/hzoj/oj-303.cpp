/*************************************************************************
	> File Name: oj-303.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 09时40分07秒
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
#define MAX_N 1000
int n, m;
char graph[MAX_N + 5][MAX_N + 5];
int ans[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct Data {
    int x, y, step;
};

int main() {
    cin >> n >> m;
    queue<Data> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '1') {
                que.push({i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        Data cur = que.front();     
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (graph[x][y] == '0') {
                ans[x][y] = cur.step + 1;
                graph[x][y] = '2';
                que.push({x, y, cur.step + 1});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            j != 1&& cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
