/*************************************************************************
	> File Name: P1186.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月10日 星期二 18时55分53秒
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
#define MAX_M 500000

struct Edge {
    int v, w, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

Edge e[MAX_M * 2];
int head[MAX_N + 5], las[MAX_N + 5], dist[MAX_N + 5];
bool vis[MAX_N + 5];
int n, m, mcnt;

inline void addEdge(int u, int v, int w) {
    mcnt++;
    e[mcnt].v = v;
    e[mcnt].w = w;
    e[mcnt].next = head[u];
    head[u] = mcnt;
    return ;
}

priority_queue<Node> que;
void dijkstra(int x, int y, bool flag) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    while (!que.empty()) que.pop();
    que.push((Node){1, 0});
    dist[1] = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int u = cur.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if ((u == x && v == y) || (u == y && v == x)) continue;
            if (vis[v] || dist[v] < dist[u] + w) continue;
            dist[v] = dist[u] + w;
            if (flag) las[v] = u;
            que.push((Node){v, dist[v]});
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    
    dijkstra( 0, 0, true);
    int x, y , s = n , ans = 0;
    while (s != 0) {
        x = las[s], y = s;
        dijkstra(x, y, false);
        ans = max(dist[n], ans);
        s = las[s];
    }
    printf("%d\n", ans);
    return 0;
}
