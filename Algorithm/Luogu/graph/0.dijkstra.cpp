/*************************************************************************
    > File Name: 0.dijkstra.cpp
    > Author: wei 
    > Mail: 1931248856@qq.com
    > Created Time: 2020年10月27日 星期二 19时56分16秒
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
    int now, dist;
    bool operator<(const struct Node &b) const {
        return this->dist > b.dist;
    }
};

//优先队列默认大顶堆

int n, m, s, arr[1005][1005], ans[1005];

int main() {
    memset(arr, 0x3F, sizeof(arr));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }
    priority_queue<Node> que;
    que.push((Node){s, 0});
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (ans[temp.now] != 0x3F3F3F3F) {
            continue;
        }
        ans[temp.now] = temp.dist;
        for (int i = 1; i <= n; ++i) {
            if (arr[temp.now][i] != 0x3F3F3F3F) {
                que.push((Node){i, temp.dist + arr[temp.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        if (ans[i] == 0x3F3F3F3F) {
            cout << "-1";
        } else {
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}
