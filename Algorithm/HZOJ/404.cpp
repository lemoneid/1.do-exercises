/*************************************************************************
	> File Name: 404.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 18 Aug 2020 04:09:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, sx, sy, ans;

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx < 1 || yy < 1 || xx > n || yy > m) {
            continue;
        }
        if (mmap[xx][yy] != mmap[x][y] && mmap[xx][yy] != '#') {
            cout << xx << " " << yy << endl;
            ans++;
            mmap[xx][yy] = '#';
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (&mmap[i][1]);
    }
    cin >> sx >> sy;
    mmap[sx][sy] = '#';
    ans = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
