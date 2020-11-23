/*************************************************************************
	> File Name: oj-639.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 09时32分02秒
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
#define MAX_N 2000
#define MAX_M 1000000

struct Edge {
    int u, v, w, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], dist[MAX_N + 5], in_degree[MAX_N + 5];
int n, m, edg_cnt, ans;
bool vis[MAX_N + 5];

inline void addEdge(int u, int v, int w) {
    e[edg_cnt].u = u; 
    e[edg_cnt].v = v; 
    e[edg_cnt].w = w; 
    e[edg_cnt].next = head[u]; 
    head[u] = edg_cnt++;
    in_degree[v]++;
    return ;
}

void topo() {
    queue<int> que;
    for (int i = 1; i <= n + m; ++i) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
        if (i <= n) dist[i] = 1;
    } 
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            dist[v] = max(dist[v], dist[cur] + w);
            in_degree[v]--;
           // cout << "u = " << e[i].u << "; v = " << e[i].v << "; w = " << e[i].w  << "; distv = " << dist[v] << "in_degreev = " << in_degree[v] << endl;
            if (in_degree[v] == 0) {
                que.push(v);    
            }
        }
    }
    for (int i = 1; i <= n + m; ++i) {
        ans = max(ans, dist[i]);
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(vis, sizeof(vis), false);
    scanf("%d%d", &n, &m);
    for (int i = 1, cnt; i <= m; ++i) {
        scanf("%d", &cnt);
        int start = n + 1, end = 0, cur, source = n + i;
        while (cnt--) {
            scanf("%d", &cur);
            vis[cur] = true; 
            start = min(start, cur);
            end = max(end, cur);
        }
        for (int j = start; j <= end; ++j) {
            if (vis[j]) addEdge(source, j, 1), vis[j] = false;
            else addEdge(j, source, 0);
        }
    }
    //for (int i = 0; i < edg_cnt; ++i) cout << "u = " << e[i].u << "; v = " << e[i].v << "; w = " << e[i].w << endl;
    topo();
    cout << ans << endl;
    return 0;
}
