/*************************************************************************
	> File Name: oj-303.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 18时03分28秒
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
#define MAX_N 1000

struct node {
    int x, y, step;
};

int n, m, ans[MAX_N + 5][MAX_N + 5];
char mmap[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    queue <node> que;
    cin >> n >> m;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '0') {
                ans[x][y] = temp.step + 1;
                mmap[x][y] = '2';
                que.push((node){x, y, ans[x][y]});
            }
        }
    }
    for (int i = 1; i<= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            j != 1 && cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
