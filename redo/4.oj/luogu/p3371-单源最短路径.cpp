/*************************************************************************
	> File Name: p3371-单源最短路径.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 11时05分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define MAX_M 500000
#define MAX_N 100000
#define INF 0x3f3f3f3f

struct Edge {
    int v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};

int n, m, start;
int cnt = 0;
Edge e[MAX_M + 5];
int head[MAX_N + 5], dist[MAX_N + 5];
bool visit[MAX_N + 5];

inline void addEdge(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    memset(visit, false, sizeof(visit));
    return ;
}

void dijskstra() {
    priority_queue<Node> que;
    que.push({start, 0});
    dist[start] = 0;
    Node cur;
    while (!que.empty()) {
        cur = que.top();
        que.pop();
        int u = cur.now;
        if (visit[u]) continue;
        visit[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (visit[v] || dist[v] < cur.w + e[i].w) continue;
            dist[v] = cur.w + e[i].w;
            que.push({v, dist[v]});
        }
    }
    return ;
}

int main() {
    init();
    cin >> n >> m >> start; 
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijskstra();
    for (int i = 1; i <= n; i++) {
        i != 1 && cout << " ";
        cout << (dist[i] == INF ? 0x7fffffff : dist[i]);
    }
    return 0;
}
