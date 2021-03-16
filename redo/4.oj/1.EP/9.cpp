/*************************************************************************
	> File Name: 9.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 09时16分07秒
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
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ans = 0;
    for (int n = 1; n <= 33; n++) {
        for (int m = n + 1; m * m + n * n < 1000; m++) {
            if (gcd(n, m) - 1) continue;
            int a = 2 * n * m;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + b + c);
                ans = a * b * c * pow(k, 3);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
