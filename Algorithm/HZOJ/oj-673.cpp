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

#define topo(que) {\
    int *in_degree = (int *)malloc(sizeof(int) * (MAX_M + 5));\
    memcpy(in_degree, degree, sizeof(int) * (MAX_M + 5));\
    for (int i = 1; i <= n; ++i) {\
        if (in_degree[i]) continue;\
        que.push(i);\
    }\
    int ans = 0;\
    int pre = 0;\
    while (!que.empty()) {\
        int cur = que.top();\
          cout << "id" << cur << endl;  \
        que.pop();\
        if (cur > pre) ans += 1, pre = cur;\
        for (int i = head[cur]; i != -1; i = e[i].next) {\
            int v = e[i].v;\
            in_degree[v]--;\
            if (in_degree[v] == 0) {\
                que.push(v);\
            }\
        }\
    }\
    cout << ans << endl;\
    free(in_degree);\
}
struct Edge {
    int v, next;
};

Edge e[MAX_M + 5];
int head[MAX_N + 5], degree[MAX_N + 5];
int n, m;

priority_queue<int> queMax;
priority_queue<int, vector<int>, greater<int>> queMin;

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d%d", &a, &b);
        e[i].v = b;
        e[i].next = head[a];
        head[a] = i;
        degree[b]++;
    }
    topo(queMax);
    topo(queMin);
    return 0;
}
