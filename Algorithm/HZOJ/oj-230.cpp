/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月04日 星期三 16时33分17秒
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

int ind[8][8];
int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 0};

void init() {
    for (int i = 0; i < 28; ++i) {
        ind[i / 5][i % 5] = 1 << i;
    }
    return ;
}
int make(int status, int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx > 4 || yy > 4) continue;
        if ((status & ind[xx][yy])) {
            status -= ind[xx][yy];
        } else {
            status += ind[xx][yy];
        }
    }
    return status;
}

int doit(int status) {
    int step = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((status & ind[i][j]) == 0) {
                status = make(status, i + 1, j);
                step++;
            }
        }
    }
    if (status != ind[5][0] - 1) return -1;
    return step;
}

int handle(int status, int s, int step) {
    if (s == 5) {
        int res = doit(status);
        return (res == -1 ? 9999 : res + step);
    }
    int ans = 9999;
    ans = min(ans, handle(status, s + 1, step));
    status = make(status, 0, s);
    ans = min(ans, handle(status, s + 1, step + 1));
    return ans;
}

void func() {
    int status = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char t;
            cin >> t;
            if (t == '1') {
                status += ind[i][j];
            }
        }
    }
    int ans = 9999;
    ans = min(ans, handle(status, 0, 0));
    if (ans == 9999) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return ;
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        func();
    }

    return 0;
}
