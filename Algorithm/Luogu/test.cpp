/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 19时29分48秒
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
#define MAX_N 1000000
#define MAX_M 1000000

struct Edge {
    int v, w, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, cnt[2];
int head[2][MAX_N + 5], dist[MAX_N + 5];
bool vis[MAX_N + 5];
Edge e[2][MAX_M + 5];

inline void  addEdge(int flag, int u, int v, int w) {
    cnt[flag]++;
    e[flag][cnt[flag]].v = v;
    e[flag][cnt[flag]].w = w;
    e[flag][cnt[flag]].next = head[flag][u];
    head[flag][u] = cnt[flag];
    return ;
}

priority_queue<Node> que;
void dijkstra(int *head, Edge *e) {
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    while (!que.empty()) que.pop();
    que.push((Node){1, 0});
    dist[1] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        int u = tmp.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (vis[v] || dist[v] < dist[u] + w) continue;
            dist[v] = dist[u] + w;
            que.push((Node){v, dist[v]});
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        addEdge(0, a, b, c);
        addEdge(1, b, a, c);
    }
    long long ans = 0;
    dijkstra(head[0], e[0]);
    for (int i = 1; i <= n; ++i) {
        ans += dist[i];
    }
    dijkstra(head[1], e[1]);
    for (int i = 1; i <= n; ++i) {
        ans += dist[i];
    }
    printf("%lld\n", ans);
    return 0;
}
