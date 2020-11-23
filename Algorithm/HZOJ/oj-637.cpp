/*************************************************************************
	> File Name: oj-637.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 21时30分20秒
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
#define MAX_N 26
#define BASE 'A'
#define INF 0x3f3f3f3f

int matrix[MAX_N + 5][MAX_N + 5], in_degree[MAX_N + 5];
int n, m;
char str[MAX_N + 5];

int haveCycle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                in_degree[j]++;
            }
        }
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    int cnt = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < n; ++i) {
            if (!matrix[cur][i]) continue;
            in_degree[i]--;
            if (in_degree[i] == 0) {
                que.push(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (in_degree[i]) {
            return 1;
        }
    }
    return 0;
}

int folyed(int n) {
    int ans[MAX_N + 5][MAX_N + 5], mfront[MAX_N + 5], mback[MAX_N + 5];
    memset(ans, 0x3f, sizeof(ans));
    memset(mfront, 0, sizeof(mfront));
    memset(mback, 0, sizeof(mback));
    memset(str, 0, sizeof(str));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                ans[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] != 0x3f3f3f3f) {
                mback[i]++;
                mfront[j]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (mback[i] + mfront[i] == n - 1) {
            cnt++;
        }
        str[mfront[i]] = BASE + i;
    }
    str[n] = '\0';
    return cnt == n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        char x, op, y;
        cin >> x >> op >> y;
        matrix[x - BASE][y - BASE] = 1;
        if (haveCycle(n)) {
            printf("Inconsistency found after %d relations.\n", i + 1);
            return 0;
        }
        if (folyed(n)) {
            printf("Sorted sequence determined after %d relations: %s.\n", i + 1, str);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}
