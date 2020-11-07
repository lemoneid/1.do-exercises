/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月04日 星期三 09时42分27秒
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
#define MAX_N 2000

struct Node {
    int x, y, step, flag;
};

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5]; // &1 无手机， &2 有手机
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    queue<Node> que;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", mmap[i] + 1);
        for (int j = 1; j <= m; ++j) {
            if (mmap[i][j] == 'S') {
                que.push((Node){i, j, 0, 0});
                check[i][i] |= 1;
            }
        }
    }
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T' && temp.flag == 1) {
                printf("%d\n", temp.step + 1);
                return 0;
            }
            if (mmap[x][y] == 'P' && (check[x][y] & 2) == 0) {
                check[x][y] |= 2;
                que.push((Node){x, y, temp.step + 1, 1});
            }
            if (mmap[x][y] == 'S' ||
                mmap[x][y] == 'T' ||
                mmap[x][y] == 'P' ||
                mmap[x][y] == '.' ) {
                    if (temp.flag == 0 && (check[x][y] & 1) == 0) {
                        que.push((Node){x, y, temp.step + 1, 0});
                        check[x][y] |= 1;
                    } else if (temp.flag == 1 && (check[x][y] & 2) == 0) {
                        que.push((Node){x, y, temp.step + 1, 1});
                        check[x][y] |= 2;
                    }
            }
        }
    } 
    cout << "No" << endl;
    return 0;
}
