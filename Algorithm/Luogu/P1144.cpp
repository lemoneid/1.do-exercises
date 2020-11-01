/*************************************************************************
	> File Name: P1144.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 20时22分28秒
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

struct Node {
    int now, w;
    bool operator<(const Node &b) const {
        return this->w> b.w;
    }
};

int n, m, mcnt, head[1000005], ans[1000005], cnt[1000005];

Edge e[4000005];

void add(int x, int y) {
    e[mcnt].v = y;
    e[mcnt].next = head[x];
    head[x] = mcnt++;
}

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    priority_queue<Node> que;
    que.push((Node){1, 0});
    ans[1] = 0;
    cnt[1] = 1;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.w > ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (ans[v] > ans[temp.now] + 1) {
                ans[v] = ans[temp.now] + 1;
                cnt[v] = cnt[temp.now];
                que.push((Node){v, ans[v]});
            } else if (ans[v] == ans[temp.now] + 1) {
                cnt[v] += cnt[temp.now];
                cnt[v] %= 100003;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }
    return 0;
}
