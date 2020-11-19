/*************************************************************************
	> File Name: P1991.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 21时05分36秒
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
#define MAX_P 500
#define MAX_M 250000

struct Edge {
    int u, v;
    double w;
};

struct UnionSet {
    int fa[MAX_P + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        } 
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

Edge e[MAX_M];
int arr[MAX_P + 5];
int s, p, mcnt;
pair<int, int> pos[MAX_P + 5];
UnionSet set;
inline void addEdge(int u, int v, double w) {
    e[mcnt].u = u;
    e[mcnt].v = v;
    e[mcnt].w = w;
    mcnt++;
    return ;
}

bool cmp(const Edge &a, const Edge &b) {return a.w < b.w;}

int main() {
    cin >> s >> p;
    for (int i = 1; i <= p; ++i) cin >> pos[i].first >> pos[i].second;
    for (int i = 1, x, y; i <= p; ++i) {
        for (int j = i + 1; j <= p; ++j) {
            int x = pos[i].first - pos[j].first;
            int y = pos[i].second - pos[j].second;
            double dist = sqrt(x * x + y * y);
            addEdge(i, j, dist);
        }
    }

    sort(e, e + mcnt, cmp);
    int count = 0; 
    double ans;
    set.init(p);
    for (int i = 0; i < mcnt; ++i) {
        int u = e[i].u, v = e[i].v;
        double w = e[i].w;
        if (set.get(u) == set.get(v)) continue;
        set.merge(u, v);
        ans = w;
        count++;
        if (count >= p - s) {
            printf("%.2lf", ans);
            return 0;
        }
    } 

    return 0;
}
