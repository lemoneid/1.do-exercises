/*************************************************************************
	> File Name: oj-638.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 21时45分34秒
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
const int MAX_N = 1500;
const int MAX_M = 50000;
struct Edge {
    int v, w, next;
};

int n, m;
int head[MAX_N + 5], dist[MAX_N + 5], in_degree[MAX_N + 5];
bool mask[MAX_N + 5];
Edge e[MAX_M + 5];

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x80, sizeof(dist));
}

inline void addEdge(int u, int v, int w) {
    static int cnt = 0;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int bellman(int start) {
    memset(mask, false, sizeof(mask));
    queue<int> que;
    que.push(start);
    mask[start] = true;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        mask[start] = false;
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (v == n) return 0;
            if (mask[v]) continue;
            mask[v] = true;
            que.push(v);
        }
    }
    return 1;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        in_degree[v]++;
    }
    if (bellman(1)) {
        cout << -1 << endl;
        return 0;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) que.push(i);
    }
    dist[1] = 0;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            dist[v] = max(dist[v], dist[now] + w);
            in_degree[v]--;
            if (in_degree[v] == 0) que.push(v);
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}
