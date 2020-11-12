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
#define MAX_N 1000
#define MAX_M 100000

struct Edge {
    int u, v, w, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, cnt[2];
int head[2][MAX_N + 5], dist[2][MAX_N + 5];
bool vis[MAX_N + 5];
Edge e[2][MAX_M + 5];

inline void  addEdge(int flag, int u, int v, int w) {
    cnt[flag]++;
    e[flag][cnt[flag]].u = u;
    e[flag][cnt[flag]].v = v;
    e[flag][cnt[flag]].w = w;
    e[flag][cnt[flag]].next = head[flag][u];
    head[flag][u] = cnt[flag];
    return ;
}

void dijkstra(int s, int flag) {
    memset(vis, false, sizeof(vis));
    priority_queue<Node> que;
    que.push((Node){s, 0});
    dist[flag][s] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        int u = tmp.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[flag][u]; i != -1; i = e[flag][i].next) {
            int v = e[flag][i].v, w = e[flag][i].w;
            if (vis[v] || dist[flag][v] < dist[flag][u] + w) continue;
            dist[flag][v] = dist[flag][u] + w;
            que.push((Node){v, dist[flag][v]});
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        addEdge(0, a, b, c);
        addEdge(1, b, a, c);
    }
    dijkstra(1, 0);
    dijkstra(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dist[0][i] + dist[1][i];
    }
    cout << ans << endl;
    return 0;
}
