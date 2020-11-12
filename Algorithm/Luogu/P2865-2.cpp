/*************************************************************************
	> File Name: P2865-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 18时54分11秒
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
#define MAX_N 5000
#define MAX_M 200000

struct Edge {
    int v, w, next;
};

struct Node {
    int now, dist;

};

Edge e[MAX_M + 5];
int n, m, mcnt, ans[2][MAX_N + 5], head[MAX_N + 5];
bool vis[MAX_N + 5];

void addEdge(int u, int v, int w) {
    e[mcnt].v = v;
    e[mcnt].w = w;
    e[mcnt].next = head[u];
    head[u] = mcnt++;
    return ;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
        if (u == 1 || v == 1) {
            ans[1][1] = min(ans[1][1], w * w);
        }
    }

    queue<int> que;
    que.push(1);
    ans[0][1] = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        vis[t] = 0;
        for (int i = head[t]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (ans[0][v] > ans[0][t] + w) {
                ans[1][v] = ans[0][v];
                ans[0][v] = ans[0][t] + w;
                if (vis[v] == 0) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
            if (ans[0][v] < ans[0][t] + w && ans[1][v] > ans[0][t] + w) {
                ans[1][v] = ans[0][t] + w;
                if (vis[v] == 0) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
            if (ans[1][v] > ans[1][t] + w) {
               ans[1][v] = ans[1][t] + w;
                if (vis[v] == 0) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    cout << ans[1][n] << endl;
    return 0;
}
