/*************************************************************************
	> File Name: 4.spfa.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 18时55分56秒
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

//bellman-队列优化
//

struct Edge {
    int v, w, next;
};

Edge edg[500005];
int n, m, s, ans[100005], mark[100005], head[100005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].v = b;
        edg[i].w = c;
        edg[i].next = head[a];
        head[a] = i;
    }
    queue<int> que;
    que.push(s);
    ans[s] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int v = edg[i].v, w = edg[i].w;
            if (ans[v] > ans[temp] + w) {
                ans[v] = ans[temp] + w;
                if (mark[v] == 0) {
                    que.push(v);
                    mark[v] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        if (ans[i] == 0x3F3F3F3F) cout << 0x7fffffff;
        else cout << ans[i];
    }

    return 0;
}
