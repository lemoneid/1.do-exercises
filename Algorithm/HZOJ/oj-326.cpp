/*************************************************************************
	> File Name: oj-326.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月22日 星期四 13时10分19秒
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
#define MAX_N 50000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    int merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            int ans  = (val[a] - val[b] + 3) % 3;
            return ans == c;
        }
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return 1;
    }
};

UnionSet u;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; ++i) {
        int d, x, y;
        cin >> d >> x >> y;
        if (d == 2 && x == y) {
            ans++;
        } else if (x > n || y > n) {
            ans++;
        } else {
            int c = d == 1 ? 0 : 2;
            ans += !u.merge(x, y, c);
        }
    }
    cout << ans << endl;
    return 0;
}
