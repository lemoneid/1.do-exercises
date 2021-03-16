/*************************************************************************
	> File Name: oj-290.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 08时52分05秒
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
#include <bitset>
using namespace std;
#define MAX_N 30000
int num[MAX_N + 5], ans[MAX_N + 5];
vector<int> e[MAX_N + 5], a;
bitset<MAX_N + 5>  bit[MAX_N + 5];
queue<int> que;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        num[y]++;
        bit[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) que.push(i);
    }
    while (!que.empty()) {
        int x = que.front();
        a.push_back(x);
        for (int i = 0; i < e[x].size(); i++) {
            int y = e[x][i];
            num[y]--;
            if (!num[y]) que.push(y);
        }
        for (int i = 1; i <= n; i++) bit[i][i] = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            int x = a[i];
            for (int j = 0; j < e[x].size(); j++) {
                bit[x] |= bit[e[x][j]];
            }
            ans[x] = bit[x].count();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
