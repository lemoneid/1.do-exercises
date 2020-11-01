/*************************************************************************
	> File Name: 1.dijkstra.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 18时06分52秒
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
    int e, dist, next;
};

struct Node {
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

Edge e[500005];
int n, m, s, ans[10005], head[10005], mark[10005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i].e = b;
        e[i].dist = c;
        e[i].next = head[a];
        head[a] = i;
    }

    priority_queue<Node> que;
    que.push((Node){s, 0});
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (ans[temp.now] < temp.dist) continue;
        ans[temp.now] = temp.dist;
        for (int i = head[temp.now]; i != -1; i = e[i].next) {
            int x = e[i].e, y = e[i].dist; 
            if (ans[x] > ans[temp.now] + y) {
                que.push((Node){x, ans[temp.now] + y});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        if (ans[i] == 0x3F3F3F3F) {
            cout << 0x7FFFFFFF;
        } else {
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}
