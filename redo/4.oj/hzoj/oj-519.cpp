/*************************************************************************
	> File Name: oj-519.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 22时05分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int getLen(long long val) {
    return floor(log10(val)) + 1;
}

int main() {
    long long l, r;
    int ans = 0;
    cin >> l >> r;
    int len_a = getLen(l);
    int len_b = getLen(r);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            for (int k = len_a; k <= len_b; k++) {
                for (int ind = 1; ind <= k; ind++) {
                    if (i == 0 && ind != 1) break;
                    if (j == 0 && ind == 1) continue;
                    long long num = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m == ind) {
                            num = num * 10 + j;
                        } else {
                            num = num * 10 + i;
                        }
                    }
                    if (num >= l && num <= r) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
