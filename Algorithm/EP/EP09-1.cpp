/*************************************************************************
	> File Name: EP09-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月31日 星期日 14时11分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b, c, k, ans = 0;
    for (int n = 1; n < 33; ++n) {
        for (int m = n + 1; m * m + n * n < 1000; ++m) {
            if (gcd(n, m) - 1) continue;
            a = 2 * n * m;
            b = m * m - n * n;
            c = m * m + n * n;
            if (1000 % (a + b + c) == 0) {
                k = 1000 / (a + b + c);
                ans = a * b * c * k * k * k;
                break;
            }
        }
        if (ans) break;
    }    
    cout << ans << endl;
    return 0;
}
