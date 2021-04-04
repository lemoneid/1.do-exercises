/*************************************************************************
	> File Name: P2865-Roadblocks-v2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 14时14分53秒
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
    int v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], dist[2][MAX_N + 5];
bool visit[MAX_N + 5];
int cnt, n, m;

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
}

inline void addEdge(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void bellman(int start) {
    memset(visit, false, sizeof(visit));
    queue<int> que;
    dist[0][start] = 0;
    que.push(start);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        visit[now] = false;
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            int val = dist[0][now] + w;
            if (dist[0][v] > val) {
                dist[1][v] = dist[0][v];
                dist[0][v] = val;
                if (visit[v] == false) {
                    visit[v] = true;
                    que.push(v);
                }
            }
            if (dist[0][v] < val && dist[1][v] > val) {
                dist[1][v] = val;
                if (visit[v] == false) {
                    visit[v] = true;
                    que.push(v);
                }
            }
            if (dist[1][v] > dist[1][now] + w) {
                dist[1][v] = dist[1][now] + w; 
                if (visit[v] == false) {
                    visit[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
        if (u == 1 || v == 1) { //更新次短路
            dist[1][1] = min(dist[1][1], w * 2);
        }
    }
    bellman(1);
    cout << dist[1][n] << endl;
    return 0;
}
