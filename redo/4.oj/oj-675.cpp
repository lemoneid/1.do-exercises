/*************************************************************************
	> File Name: oj-675.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 21时36分36秒
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

struct Edge {
    int v, w, next;
};

int n, m, c;
int head[MAX_N + 5], s[MAX_N + 5], in_degree[MAX_N + 5];
Edge e[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i =  1, u, v, w; i <= c; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[i].v = v;
        e[i].w = w;
        e[i].next = head[u];
        head[u] = i;
        in_degree[v]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            s[v] = max(s[v], s[now] + w);
            in_degree[v]--;
            if (in_degree[v] == 0) que.push(v);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d\n", s[i]);
    return 0;
}
