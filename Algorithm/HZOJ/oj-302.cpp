/*************************************************************************
	> File Name: oj-302.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月05日 星期四 15时42分22秒
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
#define MAX_N 500
#define judge(x, y) (mmap[x][y] == '.' || mmap[x][y] == 'E' || mmap[x][y] == 'X')

struct Node {
    int x, y, step;
    int status; // 0 |; 1 -;
};

int dir[5][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0};
char mmap[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5][MAX_N + 5];

int ind[10] = {1, 2, 4, 8, 16, 32, 64};

void output(Node temp) {
    printf("(%d, %d)-- step=%d, status=%d\n", temp.x, temp.y, temp.step, temp.status);
}



int solve() {
    int n, m;
    cin >> n >> m;
    if (!n || !m) return 0;
    memset(check, 0, sizeof(check));
    queue<Node> que;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'X') {
                que.push((Node){i, j, 0, 0});
            }    
        }
    }
    if (que.size() > 1) {
        int x = que.front().x, y = que.front().y;
        int i;
        for (i = 1; i < 5; ++i) {
            if (mmap[x + dir[i][0]][y + dir[i][1]] == 'X') break;
        }
        que.pop();
        que.push((Node){x, y, 0, i});
        check[x][y] += ind[i];
    } else {
        check[que.front().x][que.front().y] += ind[0];
    }
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
       // output(temp);
        for (int i = 1; i < 5; ++i) {
            if (temp.status == 0) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                int xx = temp.x + dir[i][0] * 2;
                int yy = temp.y + dir[i][1] * 2;
                if (check[x][y] & ind[i]) continue;
                if (judge(x, y) && judge(xx, yy)){
                    que.push((Node){x, y, temp.step + 1, i});
                    check[x][y] += ind[i];
                }
            } else {
                int x = temp.x + dir[temp.status][0];
                int y = temp.y + dir[temp.status][1];
                if (i == temp.status) {
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if (mmap[xx][yy] == 'O') {
                        cout << temp.step + 1 << endl;
                        return 1;
                    }
                    if (check[xx][yy] & ind[0]) continue;
                    if (mmap[xx][yy] == '.') {
                        que.push((Node){xx, yy, temp.step + 1, 0});
                        check[xx][yy] += ind[0];
         //           cout << "同"; output({xx, yy, temp.step + 1, 0});
                    }    
                } else if (temp.status == 1 &&  i == 3 ||
                        temp.status == 3 && i == 1 ||
                        temp.status == 2 && i == 4 ||
                        temp.status == 4 && i == 2 ) {
                    int xx = temp.x + dir[i][0], yy = temp.y + dir[i][1];
                    if (mmap[xx][yy] == 'O') {
                        cout << temp.step + 1 << endl;
                        return 1;
                    }
                    if (check[xx][yy] & ind[0]) continue;
                    if (mmap[xx][yy] == '.') {
                        que.push((Node){xx, yy, temp.step + 1, 0});
                        check[xx][yy] += ind[0];
           //         cout << "反"; output({xx, yy, temp.step + 1, 0});
                    }    
                } else {
                    int x1 = temp.x + dir[i][0], y1 = temp.y + dir[i][1];
                    int x2 = x + dir[i][0], y2 = y + dir[i][1];
                    if (check[x1][y1] & ind[temp.status]) continue;
                    if (judge(x1, y1) && judge(x2, y2)) {
                            que.push((Node){x1, y1, temp.step + 1, temp.status});
                            check[x1][y1] += ind[temp.status];
             //       cout << "异"; output({x1, y1, temp.step + 1, temp.status});
                    }
                }
            }
        }
    }
    cout << "Impossible" << endl;
    return 1;
}

int main() {
    while(solve());
    return 0;
}
