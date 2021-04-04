/*************************************************************************
	> File Name: P2865-Roadblocks-v1.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 13时51分14秒
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
const int MAX_N = 5000;
const int MAX_M = 200000;

struct Edge {
    int u, v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};

int head[MAX_N + 5], dist[2][MAX_N + 5];
bool visit[MAX_N + 5];
int cnt = 0, n, m;
Edge e[MAX_M + 5];

inline void addEdge(int u, int v, int w) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
}

void bellman(int start, int k) {
    memset(visit, false, sizeof(visit));
    queue<int> que;
    que.push(start);
    dist[k][start] = 0;
    visit[start] = true;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        visit[now] = false;
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dist[k][v] > dist[k][now] + w) {
                dist[k][v] = dist[k][now] + w;
                if (visit[v] == false) {
                    visit[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return ;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    bellman(1, 0);
    bellman(n, 1);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < cnt; i++) {
        int val = dist[0][e[i].u] + dist[1][e[i].v] + e[i].w;
        if (val != dist[0][n] && val < ans) {
            ans = val;
        }
    }
    cout << ans << endl;
    return 0;
}
