/*************************************************************************
	> File Name: oj-640.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 10时43分07秒
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
const int MOD = 100000007;
const int MAX_N = 5000;
const int MAX_M = 500000;
struct Edge {
    int v, next;
};

int head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5];
int ans[MAX_N + 5];
int n, m;
Edge e[MAX_M + 5];

void init() {
    memset(head, -1, sizeof(head));
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v;
        e[i].v = v;
        e[i].next = head[u];
        head[u] = i;
        in_degree[v]++;
        out_degree[u]++;
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
            ans[v] += ans[now];
            ans[v] %= MOD;
            in_degree[v]--;
            if (in_degree[v] == 0) que.push(v);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) cnt += ans[i], cnt %= MOD;
    }
    cout << cnt << endl;
    return 0;
}
