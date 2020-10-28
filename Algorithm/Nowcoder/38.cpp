/*************************************************************************
	> File Name: 38.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月24日 星期四 19时55分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 1000

struct node {
    int x, y, step;
};

int dir[4][2] = {0 , 1, 1, 0, 0, -1, -1, 0};
char mmap[MAX_N + 5][MAX_N + 5];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> &mmap[i][1];
    }
    if (mmap[1][1] == '0') {
        cout << -1 << endl;
        return 0;
    } 
    queue <node> que;
    que.push(node{1, 1, 1});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '1') {
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = '0';
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
