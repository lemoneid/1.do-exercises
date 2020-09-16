/*************************************************************************
	> File Name: oj-397.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 18 Aug 2020 02:28:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int mmap[105][105], n, m, ans;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != 0) {
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }

    ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mmap[i][j] != 0) {
                ans++;
                mmap[i][j] = 0;
                func(i, j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
