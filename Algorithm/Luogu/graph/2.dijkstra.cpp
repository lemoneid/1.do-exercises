/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月28日 星期三 11时04分34秒
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
#define MAX_N 100000
#define MAX_M 200000
#define INF 0x7fffffff

struct Edge {
    int u, v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const struct Node &b) const {
        return this->w > b.w;
    }
};

int head[MAX_N + 5], dist[MAX_N + 5];
bool vis[MAX_M + 5];
int n, m, s, cnt;
Edge e[MAX_M + 5];
priority_queue<Node> que;

inline void addEdge(int u, int v, int w) {
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
    return ;
}

void dijkstra(){
    memset(dist, 0x3F, sizeof(dist));
    memset(vis, false, sizeof(vis));
    que.push((Node){s, 0});
    dist[s] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        int u = tmp.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (vis[v] == true || dist[v] < dist[u] + e[i].w) continue;
            dist[v] = dist[u] + e[i].w;
            que.push((Node){v, dist[v]});
        }
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        cout << (dist[i] == 0x3F3F3F3F? INF: dist[i]);
    }
    cout << endl;
    return 0;
}
