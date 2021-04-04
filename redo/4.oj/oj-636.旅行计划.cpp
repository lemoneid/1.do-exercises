/*************************************************************************
	> File Name: oj-636.旅行计划.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 21时01分38秒
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
const int MAX_N = 100000;
const int MAX_M = 200000;

struct Edge {
    int v, next;
};

int ans[MAX_N + 5], head[MAX_N + 5], in_degree[MAX_N + 5];
int n, m;
Edge e[MAX_M + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        e[i].v = v;
        e[i].next = head[u];
        head[u] = i;
        in_degree[v]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) que.push(i), ans[i] = 1;
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v;
            ans[v] = max(ans[v], ans[now] + 1);
            in_degree[v]--;
            if (in_degree[v] == 0) que.push(v); 
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
