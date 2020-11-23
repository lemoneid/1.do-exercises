/*************************************************************************
	> File Name: oj-641.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 18时29分31秒
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
#define MAX_N 2000
#define MAX_M 400000
struct Edge {
    int v, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], in_degree[MAX_N + 5]; 
priority_queue<int, vector<int>, greater<int>> que;

int main() {
    memset(head, -1, sizeof(head));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d%d", &a, &b);
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i]) continue;
        que.push(i);
    }
    int flag = 0;
    while (!que.empty()) {
        int cur = que.top();
        que.pop();
        if (flag) cout << " ";
        flag = 1;
        cout << cur;
        for (int i = head[cur]; i != -1; i = e[i].next) {
            int v = e[i].v;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                que.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}
