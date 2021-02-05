/*************************************************************************
	> File Name: oj-73.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月28日 星期四 15时49分04秒
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
#define MAX_N 1000
char g[MAX_N + 5][MAX_N + 5];

struct UnionSet {
    int father[MAX_N * MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) father[i] = i;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        father[get(a)] = get(b);
    }
};

UnionSet u;
int n, m;

inline int ind(int i, int j) {
    return i * m + j + 1;
}

int main() {
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; ++i) cin >> g[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != 'O') continue;
            if (j - 1 >= 0 && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i - 1 >= 0 && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != 'O') continue;
            ans += u.get(ind(i, j)) != u.get(0);
        }
    }
    cout << ans << endl;
    return 0;
}
