/*************************************************************************
	> File Name: oj-530.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 14时17分59秒
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
#define MAX_N 50
#define MAX_M 1000
char matrix[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5];
char str[20];
int op[MAX_M + 5];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int n, m, k;
struct Data {
    int x, y, step;
};

int main() {
    cin >> n >> m;
    queue<Data> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '*') {
                que.push({i, j, 0});
                matrix[i][j] = '.';
            }
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> str;
        if (str[0] == 'N') op[i] = 0; 
        else if (str[0] == 'S') op[i] = 1;
        else if (str[0] == 'W') op[i] = 2;
        else op[i] = 3;
    }
    for (int i = 0; i < k; i++) {
        memset(check, 0, sizeof(check));
        int size = que.size();
        while (size--) {
            Data cur = que.front();
            que.pop();
            for (int j = 1; ;j++) {
                int x = cur.x + j * dir[op[i]][0];
                int y = cur.y + j * dir[op[i]][1];
                if (matrix[x][y] != '.') break;
                if (check[x][y] == 0) {
                    check[x][y] = 1;
                    que.push({x, y});
                }
            }
        }
    }
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        matrix[cur.x][cur.y] = '*';
    }
    for (int i = 1; i <= n; i++) {
        cout << matrix[i] + 1 << endl;
    }
    return 0;
}
