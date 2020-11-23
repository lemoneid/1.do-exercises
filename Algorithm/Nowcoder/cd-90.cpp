/*************************************************************************
	> File Name: cd-90.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 20时41分33秒
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
#define MAX_N 3000

struct Edge {
    int u, v, w;
};

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return ;
        fa[fx] = fy;
        return ;
    }
};

Edge e[MAX_N + 5];
int n, m, edg_cnt, dist[MAX_N + 5];
UnionSet uset;

inline void addEdge(int u, int v, int w) {
    e[edg_cnt].u = u;
    e[edg_cnt].v = v;
    e[edg_cnt].w = w;
    edg_cnt++;
    return ;
}

int main() {
    scanf("%d%d", &n, &m);
    if (n <= m) {
        cout << 0 << endl;
        return 0;
    }
    int pre = 0, cur = 0;
    scanf("%d", &pre);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &cur);
        addEdge(i - 1, i, cur - pre);
        addEdge(i, i - 1, cur - pre);
        pre = cur;
    }
    uset.init(n);
    sort(e, e + edg_cnt, [](const Edge &a, const Edge &b) {return a.w < b.w;});
    int already = 1, ans = 0;
    for (int i = 0; i < edg_cnt; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w; 
        if (uset.get(u) == uset.get(v)) continue;
        uset.merge(u, v);
        ans += w;
        cout << ans << endl;
        already++;
        if (already == n - m) break;
    }
    cout << ans << endl;

    return 0;
}
