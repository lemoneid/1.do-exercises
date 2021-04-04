/*************************************************************************
	> File Name: oj-635.神经网络.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 20时34分54秒
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
#define MAX_N 100

struct Edge {
    int v, w, next;
};

Edge e[MAX_N * MAX_N + 5];
int n, p;
int head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5];
int c[MAX_N + 5], u[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> p;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i]) que.push(i);
    }
    for (int i = 1, x, y, z; i <= p; i++) {
        cin >> x >> y >> z;
        e[i].v = y;
        e[i].w = z;
        e[i].next = head[x];
        head[x] = i;
        in_degree[y]++;
        out_degree[x]++;
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (c[now] > 0) {
                c[v] += c[now] * w;
            }
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
                c[v] -= u[v];
            }
        }
    }
    
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] || c[i] <= 0) continue;
        cout << i << " " << c[i] << endl;
        flag = 1;
    }
    if (!flag) cout << "NULL" << endl;
    return 0;
}
