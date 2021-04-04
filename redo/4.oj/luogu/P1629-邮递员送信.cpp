/*************************************************************************
	> File Name: P1629-邮递员送信.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 11时40分57秒
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
const int MAX_N = 1000;
const int MAX_M = 100000;
const int INF = 0x3f3f3f3f;

struct Edge {
    int v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};

Edge e[2][MAX_M + 5];
int head[2][MAX_N + 5], dist[2][MAX_N + 5];
bool visit[MAX_N + 5];
int cnt[2], n, m;

inline void addEdge(int k, int u, int v, int w) {
    e[k][cnt[k]].v = v;
    e[k][cnt[k]].w = w;
    e[k][cnt[k]].next = head[k][u];
    head[k][u] = cnt[k]++;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
}

void dijskstra(int k) {
    memset(visit, false, sizeof(visit));
    priority_queue<Node> que;
    que.push({1, 0});
    dist[k][1] = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int now = cur.now;
        if (visit[now]) continue;
        visit[now] = true;
        for (int i = head[k][now]; i != -1; i = e[k][i].next) {
            int v = e[k][i].v;
            if (visit[v] || dist[k][v] < cur.w + e[k][i].w) continue;
            dist[k][v] = cur.w + e[k][i].w;
            que.push({v, dist[k][v]});
        }
    }
    return ;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(0, u, v, w);
        addEdge(1, v, u, w);
    }
    dijskstra(0);
    dijskstra(1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dist[0][i] + dist[1][i];
    }
    cout << ans << endl;
    return 0;
}
