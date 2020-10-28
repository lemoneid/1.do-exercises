/*************************************************************************
<<<<<<< HEAD
	> File Name: oj-478.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 21时04分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int mmap[1005][1005];
int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(mmap, 0 , sizeof(mmap));
        int n;
        int x1, y1, x2, y2, d1, d2;
        cin >> n;
        cin >> x1 >> y1 >> d1;
        cin >> x2 >> y2 >> d2;
        mmap[x1][y1] = 1;
        mmap[x2][y2] = 1;
        int f1 = 0, f2 = 0;
        while (1) {
            do {
                if (f1 == 1) break;
                for (int i = 0; i < 4; ++i) {
                    int xx1 = x1 + dir[d1][0];
                    int yy1 = y1 + dir[d1][1];
                    if (xx1 < 0 || xx1 > n - 1 || yy1 < 0 || yy1 > n -1  || mmap[xx1][yy1]) {
                        d1 = (d1 + 1) % 4;
                        f1 = 1;
                    } else {
                        mmap[xx1][yy1] = 1;
                        f1 = 0;
                        x1 = xx1;
                        y1 = yy1;
                        break;
                    }
                }
            } while(0);
            do {
                if (f2 == 1) break;
                for (int i = 0; i < 4; ++i) {
                    int xx1 = x2 + dir[d2][0];
                    int yy1 = y2 + dir[d2][1];
                    if (xx1 < 0 || xx1 > n - 1 || yy1 < 0 || yy1 > n -1  || mmap[xx1][yy1]) {
                        d2 = (d2 + 3) % 4;
                        f2 = 1;
                    } else {
                        mmap[xx1][yy1] = 1;
                        f2 = 0;
                        x2 = xx1;
                        y2 = yy1;
                        break;
                    }
                }
            } while(0);
            if (x1 == x2 && y1 == y2) {
                cout << x1 << " " << y1 << endl;
                break;
            }
            if (f1 == 1 && f2 == 1) {
                cout << -1 << endl;
                break;
            }
        }
    }

=======
	> File Name: oj-395.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 08 Sep 2020 02:45:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int m, k;
int num[505], a[505];
int main() {
    int l = 0, r = 0, mid, cnt, sum;
    cin >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> num[i];
        r += num[i];
    }
    while (l < r) {
        mid = (l + r) >> 1, cnt = 0, sum  = 0;
        for (int i = m; i > 0; --i) {
            sum += num[i];
            if (sum > mid) {
                sum = num[i];
                a[cnt++] = i + 1;
            } else if (sum == mid) {
                sum = 0;
                a[cnt++] = i;
            }
        }
        if (sum != 0) cnt++;
        if (cnt <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << cnt << " " << k <<  endl;
    for (int i = 0; i < cnt; ++i) {
        cout << a[i] << endl;
    }
>>>>>>> e90f808277c560ccf82e32aba3c1aad0144013e6
    return 0;
}

