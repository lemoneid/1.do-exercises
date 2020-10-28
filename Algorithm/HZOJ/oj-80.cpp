/*************************************************************************
	> File Name: oj-80.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 30 Aug 2020 08:08:55 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, cnt;
};

int n, m;
char mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                que.push({i, j, 0});
            }
        }
    }
    
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'g') {
                cout << temp.cnt + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push({x, y, temp.cnt + 1});
                mmap[x][y] = '#';
            }
        }

    }
    cout << "No" << endl;
    return 0;
}
