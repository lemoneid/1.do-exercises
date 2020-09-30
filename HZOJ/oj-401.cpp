/*************************************************************************
	> File Name: oj-401.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 19时22分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct node {
    int x, y, step;
};

int dir[12][2] = {
    1, 2, 1, -2, -1, 2, -1, -2,
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2
};
int ans[505][505];
int n;

int main() {
    queue <node> que;
    que.push((node) {3, 3, 0});
    ans[3][3] = -1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 3 || y < 3 || x > 502 || y > 502 || ans[x][y]) {
                continue;
            }
            ans[x][y] = temp.step + 1;
            que.push((node){x, y, temp.step + 1});
        }
    }
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        if (x == 1 && y == 1) {
            cout << 0 << endl;
        } else {
            cout << ans[x + 2][y + 2] << endl;
        }
    }

    return 0;
}
