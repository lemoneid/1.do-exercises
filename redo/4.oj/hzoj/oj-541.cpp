/*************************************************************************
	> File Name: oj-541.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 17时18分27秒
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
const int MAX_N = 16;
const int MAX_M = 200;

int matrix[2][MAX_N + 5][MAX_N + 5];
int ans[2][1000005];

int n, m;

void func(int now, int op, int time) {
    if (now == n) {
        ans[op][++ans[op][0]] = time;
        return ;
    }
    for (int i = now + 1; i <= n; i++) {
        if (matrix[op][now][i] == 0x3f3f3f3f) continue;
        time += matrix[op][now][i];
        func(i, op, time);
        time -= matrix[op][now][i];
    }
}

int main() {
    memset(matrix, 0x3f, sizeof(matrix));
    cin >> n >> m;
    for (int i = 0, u, v, w1, w2; i < m; i++) {
        cin >> u >> v >> w1 >> w2;
        matrix[0][u][v] = matrix[0][v][u] = w1;
        matrix[1][u][v] = matrix[1][v][u] = w2;
    }
    func(1, 0, 0);
    func(1, 1, 0);
    sort(ans[0] + 1, ans[0] + ans[0][0] + 1);
    sort(ans[1] + 1, ans[1] + ans[1][0] + 1);
    int p0 = 1, p1 = 1;
    while (p0 <= ans[0][0] && p1 <= ans[1][0]) {
        if (ans[0][p0] == ans[1][p1]) {
            cout << ans[0][p0];
            return 0;
        }
        if (ans[0][p0] < ans[1][p1]) p0++;
        else p1++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

