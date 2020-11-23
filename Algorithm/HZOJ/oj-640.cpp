/*************************************************************************
	> File Name: oj-640.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 20时36分38秒
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
#define MAX_N 5000
#define MAX_M 500000
#define MOD 100000007

struct Edge {
    int v, next;
};

Edge e[MAX_M + 5];
int n, m, head[MAX_N + 5], ans[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }

    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i]) continue;
        ans[i] = 1;
        que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v;
            ans[v] += ans[cur];
            ans[v] %= MOD;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (out_degree[i] == 0) {
            res += ans[i];
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
