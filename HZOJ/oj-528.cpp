/*************************************************************************
	> File Name: oj-528.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 30 Aug 2020 06:39:12 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int n, x, y;
int mmap[105][105];
int flag[105];
struct node {
    int num;
    int step;
};

int main() {
    queue <node> que;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mmap[i][j];
      }
    }

    que.push({x, 0});
    flag[x] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.num == y) {
            cout << temp.step  - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (mmap[temp.num][i] == 1 && !flag[i]) {
                flag[i] = 1;
                que.push({i, temp.step + 1});
            }
        }
    }
    cout << 0 << endl;

    return 0;
}
