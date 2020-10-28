/*************************************************************************
	> File Name: oj-519.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 19时30分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long l, r, ans;
int main() {
    cin >> l >> r;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j) continue;
            for (int k = 3; k < 18; ++k) {
                for (int id  = 1; id <= k; ++id) {
                    if (id == 1 && j == 0) continue;
                    if (id != 1 && i == 0) break;
                    long long t = 0;
                    for (int m = 1; m <= k; ++m) {
                        if (m == id) t = t * 10 + j;
                        else t = t * 10 + i;
                    }
                    if (t >= l && t <= r) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
