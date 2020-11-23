/*************************************************************************
> File Name: oj-673.cpp
> Author: yanzhiwei 
> Mail: 1931248856@qq.com
> Created Time: 2020年11月20日 星期五 16时11分34秒
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
#define MAX_M 100000

struct Edge {
    int v, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], in_degree[MAX_N + 5], dist[MAX_N + 5];
int n, m, mark[MAX_N + 5];
int ans1, ans2;

void dfs(int left, int pre, int ans) {
    if (left == 0) {
        for (int i = 0; i < n; ++i) {
            cout << dist[i] << " ";
        }
        cout << endl;
        return ;
    }
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        if (mark[i] || in_degree[i]) continue;
        vec.push_back(i);
    }
    for (auto cur : vec) {
        if (cur == n) { 
            cout << "zhi-";
            for (int i = 0; i < n - left; ++i) {
                cout << dist[i] << " ";
            }
            cout << endl;
            continue ;
        }
        mark[cur] = 1;
        for (int i = head[cur]; i != -1; i = e[i].next) {
            in_degree[e[i].v]--;
        }
        if (cur > pre) ans += 1;
        dist[n - left] = cur;
        dfs(left - 1, max(cur, pre), ans);
        if (cur > pre) ans -= 1;
        mark[cur] = 0;
        for (int i = head[cur]; i != -1; i = e[i].next) {
            in_degree[e[i].v]++;
        }
    }
    return ;
}
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d%d", &a, &b);
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }

    ans1 = 0, ans2 = n + 1;
    dfs(n, 0, 0);
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}
