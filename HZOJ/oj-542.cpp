/*************************************************************************
	> File Name: oj-542.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月20日 星期二 18时13分52秒
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

int t, n, h, r;
int q[1005][3], s[1005], e[1005], cnt, check[1005], arr[1005][1005];

int func(int now) {
    if (e[now] == 1) return 1;
    for (int i = 1; i <= n; ++i) {
        if (check[i] == 0 && arr[now][i] == 1) {
            check[i] = 1;
            if (func(i) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> t;
    while (t--) {
        memset(e, 0, sizeof(e));
        memset(check, 0, sizeof(check));
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; ++i) {
            cin >> q[i][0] >> q[i][1] >> q[i][2];
            if (q[i][2] <= r) {
                s[cnt++] = i;
            }
            if (q[i][2] + r >= h) {
                e[i] = 1;
            }
            for (int j = 1; j < i; ++j) {
               int t0 = q[i][0] - q[j][0], t1 = q[i][1] - q[j][1], t2 = q[i][2] - q[j][2];
                if (sqrt(t0 * t0 + t1 * t1 + t2 * t2) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < cnt; ++i) {
            if (check[s[i]] == 0) {
                check[s[i]] = 1;
                if (func(s[i])) {
                    flag =  1;
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
        if (!flag) cout << "No" << endl;
    }

    return 0;
}
