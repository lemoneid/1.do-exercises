/*************************************************************************
	> File Name: oj-635.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 19时03分55秒
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
#define MAX_N 100
struct Edge {
    int v, w, next;
};

Edge e[MAX_N * MAX_N + 5];
int n, m, head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5];
int c[105], u[105];

int main() {
    memset(head, -1, sizeof(head));
    queue<int> que;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> u[i];
        if (c[i] == 0) continue;
        que.push(i);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i].v = b;
        e[i].w = c;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (c[cur] > 0) {
                c[v] += c[cur] * w;
            }
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
                c[v] -= u[v];
            }
        }
    }

    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (out_degree[i] == 0 && c[i] > 0) {
            flag = 1;
            cout << i << " " << c[i] << endl;
        }
    }
    if (flag == 0) cout << "NULL" << endl;
    return 0;
}
