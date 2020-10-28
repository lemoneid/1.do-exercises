/*************************************************************************
	> File Name: oj-535.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 18 Aug 2020 02:09:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[55][55];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int sx, sy, ans, w, h;

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            ans++;
            mmap[xx][yy] = '#';
            func(xx, yy);
        }
    }
}

int main() {

    cin >> h >> w;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    ans = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
