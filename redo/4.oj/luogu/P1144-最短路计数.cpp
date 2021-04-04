/*************************************************************************
	> File Name: P1144-最短路计数.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 13时23分58秒
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
const int MAX_N = 1000000;
const int MAX_M = 4000000;
const int MOD = 100003;

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};

struct Edge {
    int v, next;
};

int head[MAX_N + 5], dist[MAX_N + 5], ans[MAX_N + 5];
bool visit[MAX_N + 5];
int n, m, cnt;
Edge e[MAX_M + 5];
inline void addEdge(int u, int v) {
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    memset(ans, 0, sizeof(ans));
}

void dijskstra(int start) {
    memset(visit, false, sizeof(visit));
    priority_queue<Node> que;
    que.push({start, 0});
    dist[start] = 0;
    ans[start] = 1;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int now = cur.now;
        if (visit[now]) continue;
        visit[now] = true;
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (visit[v] || dist[v] < cur.w + 1) continue;
            if (dist[v] == cur.w + 1) {
                ans[v] += ans[now];
            }
            else {
                dist[v] = cur.w + 1;
                ans[v] = ans[now];
                que.push({v, dist[v]});
            }
            ans[v] %= MOD;
        }
    }
}


int main() {
    init();
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dijskstra(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
