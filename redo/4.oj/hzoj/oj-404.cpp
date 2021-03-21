/*************************************************************************
	> File Name: oj-404.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 12时35分31秒
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
#define MAX_N 3000
char matrix[MAX_N + 5][MAX_N + 5];
int n, m, k;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int check[MAX_N + 5][MAX_N + 5];
vector<pair<int, int> > arr;

struct Data {
    int x, y;
    char val;
};
void bfs(int sx, int sy) {
    queue<Data> que;
    arr.clear();
    que.push({sx, sy, matrix[sx][sy]});
    check[sx][sy] = 1;
    int cnt = 0;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (check[x][y] || matrix[x][y] == cur.val) continue;
            que.push({x, y, matrix[x][y]});
            arr.push_back({x, y});
            check[x][y] = 1;
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        check[arr[i].first][arr[i].second] = cnt;
    }
    check[sx][sy] = cnt;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue;
            bfs(i, j);
        }
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        cout << check[x][y] << endl;
    }
    return 0;
}
