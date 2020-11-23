/*************************************************************************
	> File Name: 5.topo.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 18时16分27秒
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

struct Edge {
    int v, next;
};

Edge e[10005];
int n, m, head[10005], in_degree[10005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    stack<int> stk;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            stk.push(i);
        }
    }

    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        cout << cur << "-" ;
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                stk.push(v);
            }
        }
    }

    return 0;
}
