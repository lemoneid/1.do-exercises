/*************************************************************************
	> File Name: P1265.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 18时16分40秒
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

struct Node {
    int now;
    double val;
    bool operator<(const Node &b) const {
        return this->val > b.val;
    }
};

int n, matrix[5005][2], mark[5005];
double ans, dist[5005];

inline double func(int a, int b) {
    double x = matrix[a][0] - matrix[b][0];
    double y = matrix[a][1] - matrix[b][1];
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> matrix[i][0] >> matrix[i][1];
        dist[i] = 99999999;
    }
    int already = 0;
    priority_queue<Node> que;
    que.push((Node){1, 0});
    dist[1] = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        if (mark[cur.now]) continue;
        mark[cur.now] = 1;
        already += 1;
        ans += cur.val;
        if (already == n) break;
        for (int i = 1; i <= n; ++i) {
            if (i == cur.now) continue;
            double tmp = func(i, cur.now);
            if (tmp < dist[i]) {
                dist[i] = tmp;
                que.push((Node){i, dist[i]});
            }
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
