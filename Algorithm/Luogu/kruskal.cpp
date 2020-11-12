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
#define MAX_M 200000
#define MAX_N 5000

struct Edge {
    int u, v, w;
};

bool cmp(const struct Edge &a, const struct Edge &b) {
    return a.w < b.w;
}

Edge e[MAX_M + 5];
int n, m, ans, myUnionSet[MAX_N + 5], already = 1;

int find_root(int x) {
    return myUnionSet[x] = (myUnionSet[x] == x ? x : find_root(myUnionSet[x]));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w; 
    }
    for (int i = 0; i <= n; ++i) {
        myUnionSet[i] = i;
    }
    sort(e, e + m, cmp);
    for (int i = 0; i <= m; ++i) {
        int sr = find_root(e[i].u), er = find_root(e[i].v);
        if (sr != er) {
            already++;
            ans += e[i].w;
            myUnionSet[sr] = er;
            if (already == n) {
                break;
            }
        }
        
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
    return 0;
}
