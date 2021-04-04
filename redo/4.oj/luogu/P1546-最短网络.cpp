/*************************************************************************
	> File Name: P1546-最短网络.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 15时17分22秒
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
const int MAX_N = 100;
int matrix[MAX_N + 5][MAX_N + 5];
int dist[MAX_N + 5];
bool visit[MAX_N + 5];
int already, ans;

struct Node {
    int now, w;
    bool operator<(const Node &obj) const {
        return this->w > obj.w;
    }
};
void init() {
    memset(dist, 0x3f, sizeof(dist));
    memset(visit, false, sizeof(visit));
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    int start = 1;
    priority_queue<Node> que;
    dist[start] = 0;
    que.push({start, 0});
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        int now = cur.now;
        if (visit[now]) continue;
        visit[now] = true;
        ans += cur.w;
        already++;
        if (already == n) break;
        for (int i = 1; i <= n; i++) {
            int val = matrix[now][i];
            if (visit[i] || dist[i] < val) continue;
            dist[i] = val;
            que.push({i, val});
        }
    }
    cout << ans << endl;
    return 0;
}
