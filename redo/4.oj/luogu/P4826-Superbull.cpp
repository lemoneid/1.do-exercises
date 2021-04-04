/*************************************************************************
	> File Name: P4826-Superbull.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 19时28分16秒
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
const int MAX_N = 2000;

struct Edge {
    int v, w, next;
};

int head[MAX_N + 5], dist[MAX_N + 5], num[MAX_N + 5];
bool visit[MAX_N + 5];
Edge e[MAX_N * MAX_N * 2 + 5];
int n, cnt;

void init() {
    memset(head, -1, sizeof(head));
    memset(dist, -1, sizeof(dist));
}

inline void addEdge(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w < obj.w;
    }
};

int prime(int start) {
    memset(visit, false, sizeof(visit));
    priority_queue<Node> que;
    que.push({start, 0});
    dist[start] = 0;
    int alreaday = 0, ans = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int now = cur.now;
        if (visit[now]) continue;
        visit[now] = true;
        alreaday++;
        ans += cur.w;
        if (alreaday == n) break;
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, val = e[i].w;
            if (visit[v] || dist[v] > val) continue;
            dist[v] = val;
            que.push({v, val});
        }
    }
    return ans;
}

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            addEdge(i, j, num[i] ^ num[j]);
            addEdge(j, i, num[i] ^ num[j]);
        }
    }
    cout << prime(1) << endl;
    return 0;
}
