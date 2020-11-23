/*************************************************************************
	> File Name: oj-638.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 19时54分26秒
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
#define MAX_N 1500
#define MAX_M 50000

struct Edge {
    int v, w, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], in_degree[MAX_N + 5], ans[MAX_N + 5];
int n, m;

int func() {
    int mark[MAX_N + 5] = {0, 1};
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        mark[cur] = 0;
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (v == n) {
                return 0;
            }
            if (mark[v] == 0) {
                mark[v] = 1;
                que.push(v);
            }
        }
    }
    return 1;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x80, sizeof(head));
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        e[i].v = b;
        e[i].w = c;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    if (func()) {
        cout << -1 << endl;
        return 0;
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    ans[1] = 0;
    
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            ans[v] = max(ans[v], ans[cur] + w);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
            }
        }
    }
    cout << ans[n] << endl;
    return 0;
}
