/*************************************************************************
	> File Name: prim.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 19时55分58秒
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

struct Edge {
    int v, w, next;
};

struct Node {
    int now, val;
    bool operator<(const struct Node &b) const {
        return this->val > b.val;
    }
};

Edge e[400005];
int n, m, ans, edg_cnt, head[5005], already, dist[5005], mark[5005];

inline void addEdge(int u, int v, int w) {
    e[edg_cnt].v = v;
    e[edg_cnt].w = w;
    e[edg_cnt].next = head[u];
    head[u] = edg_cnt++;

}

int main() {
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    int res = 0;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
        res += w;
    }
    priority_queue<Node> que;
    que.push((Node){1, 0});
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (mark[tmp.now] == 1) continue;
        mark[tmp.now] = 1;
        ans += tmp.val;
        already++;
        if (already == n) break;
        for (int i = head[tmp.now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (mark[v] == 0 && dist[v] > w) {
                dist[v] = w;
                que.push((Node){v, w});
            }
        }
    }
    cout << res - ans << endl;
    return 0;
}
