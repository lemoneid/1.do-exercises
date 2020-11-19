/*************************************************************************
	> File Name: kruskal.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 19时31分48秒
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
#define MAX_M 1000000
#define MAX_N 1000
#define MAX_K 500

struct Edge {
    int u, v;
    double w;
};

bool cmp(const struct Edge &a, const struct Edge &b) {
    return a.w < b.w;
}

Edge e[MAX_M + 5];
int n, m, ans, myUnionSet[MAX_N + 5], already = 1, mcnt;
int monkey[MAX_K + 5], tree[MAX_N][2];
int find_root(int x) {
    return myUnionSet[x] = (myUnionSet[x] == x ? x : find_root(myUnionSet[x]));
}


inline void addEdge(int u, int v, double w) {
    e[mcnt].u = u;
    e[mcnt].v = v;
    e[mcnt].w = w;
    mcnt++;
}

int main() {
    cin >>  n;
    for (int i = 0; i < n; ++i) {
        cin >> monkey[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> tree[i][0] >> tree[i][1]; 
        myUnionSet[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            double x = tree[i][0] - tree[j][0];
            double y = tree[i][1] - tree[j][1];
            double res = sqrt(x * x + y * y);
            addEdge(i, j, res);
            addEdge(j, i, res);
        }
    }
    sort(e, e + mcnt, cmp);
    double mmax = 0;
    for (int i = 0; i < mcnt; ++i) {
        int sr = find_root(e[i].u), er = find_root(e[i].v);
        if (sr != er) {
            already++;
            ans += e[i].w;
            mmax = max(mmax, e[i].w);
            myUnionSet[sr] = er;
            if (already == m) {
                break;
            }
        }
        
    }
    int fin = 0;
    for (int i = 0; i < n; ++i) {
        if (monkey[i] >= mmax) fin++;
    }
    cout << fin << endl;
    return 0;
}
