/*************************************************************************gG
	> File Name: P2865.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 18时08分35秒
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
    int u, v, w, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

int head[MAX_N + 5], ans[MAX_N + 5], ans1[MAX_N + 5];
bool vis[MAX_N + 5];
Edge e[MAX_M + 5];
int n, m, mcnt;
priority_queue<Node> que;

inline void addEdge(int u, int v, int w) {
    e[mcnt].u = u;
    e[mcnt].v = v;
    e[mcnt].w = w;
    e[mcnt].next = head[u];
    head[u] = mcnt++;
    return ;
}


void dijkstra(int s, int *dist) {
    memset(vis, false, sizeof(vis));
    cout << "dijkstra" << endl;
    while (!que.empty()) que.pop();
    que.push((Node){s, 0});
    dist[s] = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int u = cur.now;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            cout << i << endl;
            if (vis[v] == true || dist[v] < dist[u] + w) continue;
            dist[v] = dist[u] + w;
            que.push((Node){v, dist[v]});
        }
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(int));
    memset(ans, 0x3f, sizeof(ans));
    memset(ans1, 0x3f, sizeof(ans1));
    for (int i = 0; i < 100; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    cout << e[0].next << endl;
    cout << "--test--" << endl;
    cout << "ans-add-" << ans << "; size-" << sizeof(ans) << endl;
    dijkstra(1, ans);
    cout << "--test--" << endl;
    dijkstra(n, ans1);
    int mmin = ans[n], res = 0x3f3f3f3f;
    cout << "--test--" << endl;
    for (int i = 0; i < mcnt; ++i) {
            int tmp = ans[e[i].u] + ans1[e[i].v] + e[i].w;
            if (tmp == mmin) continue;
            res = min(tmp, res);
    } 
    cout << res << endl;
    return 0;
}
