/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 18时17分03秒
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

char mmap[155][155];
int n, m;
int dir[8][2] = {
    1, 2, 1, -2,
    -1, 2, -1, -2,
    2, 1, 2, -1,
    -2, 1, -2, -1
};


struct node {
    int x, y, step;
};

int main() {
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    queue <node> que;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                que.push((node){i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = '*';
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
