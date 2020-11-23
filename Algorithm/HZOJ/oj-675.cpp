/*************************************************************************
	> File Name: oj-675.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月20日 星期五 16时45分03秒
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

struct Edge {
    int v, w, next;
};

struct Node {
    int id, time;
    bool operator<(const Node &b) const {
        return this->time > b.time;
    }
};

Edge e[MAX_N + 5];
int head[MAX_N + 5], ans[MAX_N + 5], in_degree[MAX_N + 5];
int n, m, k;

void topo() {
    priority_queue<Node> que;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            que.push((Node){i, ans[i]});
        }
    }
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        for (int i = head[cur.id]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            ans[v] = max(ans[v], ans[cur.id] + w);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push((Node){v, ans[v]});
            }
        }
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> ans[i];
    }
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        e[i].v = v;
        e[i].w = w;
        e[i].next = head[u];
        head[u] = i;
        in_degree[v]++;
    }
    topo();
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
