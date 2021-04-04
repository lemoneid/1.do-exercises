/*************************************************************************
	> File Name: oj-641-拓扑排序.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 20时11分47秒
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

const int MAX_N = 2000;

struct Edge {
    int v, next;
};

struct Node {
    int x;
    bool operator<(const Node &obj) const {
        return this->x > obj.x;
    }
};

Edge edge[MAX_N * MAX_N + 5];
int n, m, head[MAX_N + 5], in_degree[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        edge[i].v = v;
        edge[i].next = head[u];
        head[u] = i;
        in_degree[v]++;
    }
    priority_queue<Node> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push({i});
        }
    }
    int flag = 0;
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        if (flag == 1) {
            cout << " ";
        }
        flag = 1;
        cout << cur.x;
        for (int i = head[cur.x]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            in_degree[v]--;
            if (in_degree[v] == 0) que.push({v});
        }
    }
    cout << endl;
    return 0;
}
