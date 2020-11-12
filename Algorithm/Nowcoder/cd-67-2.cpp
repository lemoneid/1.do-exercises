/*************************************************************************
	> File Name: cd-67-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 15时06分03秒
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
#define MAX_N 200000
struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

struct Edge {
    int v, next;
};

int head[MAX_N + 5], dist[MAX_N + 5], ans[MAX_N + 5];
bool vis[MAX_N + 5];
Edge e[MAX_N * 2+ 5];
priority_queue<Node> que;
int n, cnt;

inline void addEdge(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
    return ;
}

void dijkstra(int s) {
    memset(vis, false, sizeof(vis));
    que.push((Node){s, 0});
    dist[s] = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int u = cur.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (vis[v] || dist[v] < dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            que.push((Node){v, dist[v]});
        }
    }

    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d", &n);
    int s;
    for (int i = 0, a; i < n; ++i) {
        scanf("%d", &a);
        if (i == a) s = i;
        else {
            addEdge(i, a);
            addEdge(a, i);
        }
    }
    dijkstra(s);
    for (int i = 0; i < n; ++i) {
        //cout << dist[i] << endl;
        if (dist[i] == 0x3f3f3f3f) continue;
        ans[dist[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
