/*************************************************************************
	> File Name: temp.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月27日 星期日 10时18分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1005
int num[MAX_N][MAX_N], utd[MAX_N][MAX_N], dtu[MAX_N][MAX_N], sum[MAX_N][MAX_N], ans[MAX_N][2];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            utd[i][j] = max(utd[i - 1][j], utd[i - 1][j - 1]) + num[i][j];
        }
    } 
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= i; ++j) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
            sum[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }

    for (int i = 2; i <= n; ++i) {
        int x = 0, y = 0;
        for (int j = 1; j <= i; ++j) {
            if (sum[i][j] > sum[i][x]) {
                x = j;
            }
        }
        for (int j = 1; j <= i; ++j) {
            if (j != x && sum[i][j] > sum[i][y]) {
                y = j;
            }
        }
        ans[i][0] = x;
        ans[i][1] = y;
    }

    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        if (a == 1) {
            cout << -1 << endl;
            continue;
        }
        printf("%d\n", ans[a][0] == b ? sum[a][ans[a][1]] : sum[a][ans[a][0]] );
    }

    return 0;
}
