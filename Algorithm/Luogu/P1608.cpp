/*************************************************************************
	> File Name: P1608.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 21时06分00秒
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

#define MAX_N 2000
#define MAX_M 4000000

struct Edge {
    int v, w, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

int head[MAX_N + 5], dist[MAX_N + 5], cnt[MAX_N + 5];
Edge e[MAX_M + 5];
int n, m, mcnt;
int vis[MAX_N + 5][MAX_N + 5];

inline void addEdge(int u, int v, int w) {
    e[++mcnt].v = v;
    e[mcnt].w = w;
    e[mcnt].next = head[u];
    head[u] = mcnt;
    return ;
}

int main() {
    memset(dist, 0x3f, sizeof(dist));
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        if (vis[a][b] == 0 || vis[a][b] > c) {
            addEdge(a, b, c);
            vis[a][b] = c;
        }
    }
    priority_queue<Node> que;
    que.push((Node){1, 0});
    dist[1] = 0;
    cnt[1] = 1;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        int u = tmp.now;
        if (tmp.dist > dist[u]) continue;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w + dist[u];
            if (dist[v] > w) {
                dist[v] = w;
                cnt[v] = cnt[u];
                que.push((Node){v, dist[v]});
            } else if (dist[v] == w) {
                cnt[v] += cnt[u];
            }
        }
    } 
    if (dist[n] == 0x3f3f3f3f) {
        cout << "No answer" << endl;
        return 0;
    }
    cout << dist[n] << " " << cnt[n] << endl;
    return 0;
}
