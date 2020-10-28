/*************************************************************************
	> File Name: oj-342.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 19时33分43秒
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
#define MAX_N 5
int cnt[MAX_N + 5];

void solve(int k) {
    if (k == 0) return ;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < k; ++i) cin >> cnt[i];
    long long f[cnt[0] + 1][cnt[1] + 1][cnt[2] + 1][cnt[3] + 1][cnt[4] + 1];
    memset(f, 0, sizeof(f));
    f[0][0][0][0][0] = 1;
    for (int i0 = 0; i0 <= cnt[0]; i0++) {
        for (int i1 = 0; i1 <= cnt[1]; i1++) {
            for (int i2 = 0; i2 <= cnt[2]; i2++) {
                for (int i3 = 0; i3 <= cnt[3]; i3++) {
                    for (int i4 = 0; i4 <= cnt[4]; i4++) {
                        long long val = f[i0][i1][i2][i3][i4];
                        if (i0 >= i1 && i0 >= i2 && i0 >= i3 && i0 >= i4 && i0 < cnt[0]) {
                            f[i0 + 1][i1][i2][i3][i4] += val;
                        }
                        if (i1 >= i2 && i1 >= i3 && i1 >= i4 && i1 < cnt[1]) {
                            f[i0][i1 + 1][i2][i3][i4] += val;
                        }
                        if (i2 >= i3 && i2 >= i4 && i2 < cnt[2]) {
                            f[i0][i1][i2 + 1][i3][i4] += val;
                        }
                        if (i3 >= i4 && i3 < cnt[3]) {
                            f[i0][i1][i2][i3 + 1][i4] += val;
                        }
                        if (i4 < cnt[4]) {
                            f[i0][i1][i2][i3][i4 + 1] += val;
                        }
                    }    
                }
            }   
        }
    }    
    cout << f[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return ;
}

int main() {
    int k;
    while (cin >> k) solve(k);
    return 0;
}
