/*************************************************************************
	> File Name: oj-404.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 19时41分36秒
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
    int x, y;
    char ch;
};

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];
int n, m, sx, sy, ans = 1;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    cin >> sx >> sy;
    queue <node> que;
    que.push((node){sx, sy, mmap[sx][sy]});
    mmap[sx][sy] = 0;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] != 0 && mmap[x][y] != temp.ch) {
                ans++;
                que.push((node){x, y, mmap[x][y]});
                mmap[x][y] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
