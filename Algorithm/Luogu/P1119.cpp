/*************************************************************************
	> File Name: P1119.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月10日 星期二 18时34分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 200
#define MAX_M 20000
int n, m, q;
int matrix[MAX_N + 5][MAX_N + 5];
int t[MAX_N + 5];

inline void update(int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
    }
    return ;
}

int main() {
    memset(matrix, 0x3f, sizeof(matrix));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", t + i);
        matrix[i][i] = 0;
    }
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        matrix[a][b] = c;
        matrix[b][a] = c;
    }
    scanf("%d", &q);
    int now = 0;
    for (int i = 0, a, b, c; i < q; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        while (t[now] <= c && now < n) update(now), now++;
        if (t[a] > c || t[b] > c) printf("-1\n");
        else if (matrix[a][b] == 0x3f3f3f3f) printf("-1\n");
        else printf("%d\n",matrix[a][b]);
    }
    return 0;
}
