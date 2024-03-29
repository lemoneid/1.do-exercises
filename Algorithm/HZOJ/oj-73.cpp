/*************************************************************************
	> File Name: oj-73.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月19日 星期一 22时13分43秒
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
#define MAX_N 1000
#define MAX_M 1000000
#define ind(i, j) ((i) * (m) + (j) + 1)
char mmap[MAX_N + 5][MAX_N + 5];

struct UnionSet {
    int fa[MAX_M + 5];
    int init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] - x ? get(fa[x]) : x);
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; ++i) {
        cin >> mmap[i];
        for (int j = 0; j < m; ++j) {
            if (mmap[i][j] == 'X') continue;
            if (i && mmap[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (j && mmap[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (mmap[i][j] == 'X') continue;
            if (u.get(ind(i, j)) - u.get(0)) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
