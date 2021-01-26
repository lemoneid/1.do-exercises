/*************************************************************************
	> File Name: oj-571.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 22时33分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define MAX_N 100

int mmap[MAX_N + 5][MAX_N + 5], check[MAX_N + 5];
int n, x, y, ans = -1;
struct Node {
    int now, step;
};

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mmap[i][j];
        }
    }

    queue<Node> que;
    que.push({x, 0});
    while (!que.empty()) {
        Node cur = que.front();
        que.pop();
        if (cur.now == y) {
            cout << cur.step - 1 << endl;
            break;
        }
        for (int i = 1; i <= n; ++i) {
            if (!check[i] && mmap[cur.now][i]) {
                check[i] = 1;
                que.push({i, cur.step + 1});
            }
        }
    }
    return 0;
}
