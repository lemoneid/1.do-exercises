/*************************************************************************
	> File Name: oj-478.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 21时04分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0};
int check[1005][1005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0 , sizeof(check));
        int n, x1, y1, x2, y2, d1, d2;
        int f1 = 0, f2 = 0;
        cin >> n >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
        check[x1][y1] += 1;
        check[x2][y2] += 2;
        while (1) {
            if (x1 == x2 && y1 == y2) {
                cout << x1 << " " << y1 << endl;
                break;
            }
            if (f1 == 1 && f2 == 1) {
                cout << -1 << endl;
                break;
            }
            do {
                if (f1 == 1) break;
                for (int i = 0; i < 4; ++i) {
                    int tx = x1 + dir[d1][0];
                    int ty = y1 + dir[d1][1];
                    if (tx < 0 || tx > n - 1 || ty < 0 || ty > n -1  || (check[tx][ty] & 1)) {
                        d1 = (d1 + 1) % 4;
                        f1 = 1;
                    } else {
                        check[tx][ty] += 1;
                        f1 = 0;
                        x1 = tx;
                        y1 = ty;
                        break;
                    }
                }
            } while(0);
            do {
                if (f2 == 1) break;
                for (int i = 0; i < 4; ++i) {
                    int tx = x2 + dir[d2][0];
                    int ty = y2 + dir[d2][1];
                    if (tx < 0 || tx > n - 1 || ty < 0 || ty > n -1  || (check[tx][ty] & 2)) {
                        d2 = (d2 - 1 + 4 ) % 4;
                        f2 = 1;
                    } else {
                        check[tx][ty] += 2;
                        f2 = 0;
                        x2 = tx;
                        y2 = ty;
                        break;
                    }
                }
            } while(0);
        }
    }

    return 0;
}

