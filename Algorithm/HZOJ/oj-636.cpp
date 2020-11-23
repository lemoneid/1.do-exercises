/*************************************************************************
	> File Name: oj-636.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 19时40分30秒
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
#define MAX_M 200000
#define MAX_N 100000
struct Edge {
    int u, v, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], in_degree[MAX_N + 5], ans[MAX_N + 5];
int n, m;

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }

    queue<int> que;

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v;
            ans[v] = max(ans[v], ans[cur] + 1);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
