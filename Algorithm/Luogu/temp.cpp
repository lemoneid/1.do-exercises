/*************************************************************************
	> File Name: P1629.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 19时44分12秒
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
    int v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const struct Node &b) const {
        return this->w > b.w;
    }
};

int n, m, head[2][1100055], ans[2][1100055];
Edge e[2][110005];

void func(int x) {
    priority_queue<Node> que;
    que.push((Node){1, 0});
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (ans[x][temp.now] <= temp.w) continue;
        ans[x][temp.now] = temp.w;
        for (int i = head[x][temp.now]; i != -1; i = e[x][i].next) {
            int  v = e[x][i].v, w = e[x][i].w;
            if (ans[x][v] > ans[x][temp.now] + w) {
                que.push((Node){v, ans[x][temp.now] + w});
            }
        }
    }
    return ;
}


int main() {
    ios::sync_with_stdio(false);
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[0][i].v = b;
        e[0][i].w = c;
        e[0][i].next = head[0][a];
        head[0][a] = i;
        e[1][i].v = a;
        e[1][i].w = c;
        e[1][i].next = head[1][b];
        head[1][b] = i;
    }
    func(0);
    func(1);
    long long ret = 0;
    for (int i = 2; i <= n; ++i) {
        ret += ans[0][i] + ans[1][i];
    }
    printf("%lld\n", ret);
    return 0;
}
