/*************************************************************************
	> File Name: 5.最短路.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月22日 星期一 21时39分59秒
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
#define MAX_N 1000

int g[MAX_N + 5][MAX_N + 5];
int ans[MAX_N + 5];
inline void add(int a, int b) {
    g[a][++g[a][0]] = b;
    g[b][++g[b][0]] = a;
    return ;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        add(a, b);
    }
    queue<int> q;
    ans[c] = 1;
    q.push(c);
    while (!q.empty()) {
        int ind = q.front();
        for (int i = 1; i <= g[ind][0]; ++i) {
            int to = g[ind][i];
            if (ans[to]) continue;
            ans[to] = ans[ind] + 1;
            q.push(to);
        }
        q.pop();
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] - 1 << endl;
    }

    return 0;
}
