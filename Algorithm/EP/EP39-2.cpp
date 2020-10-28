/*************************************************************************
	> File Name: EP39-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月02日 星期二 21时01分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    for (int n = 1; n <= 33; ++n) {
        for (int m = n + 1; m <= 33; ++m) {
            if (gcd(n, m) - 1) continue;
            int sum = 2 * m *n + 2 * m * m; 
            for (int p = sum; p <= max_n; p += sum) {
                cnt[p] += 1; 
            }
        }
    }
    int p = 1;
    for (int i = 1; i <= max_n; ++i) {
        if (cnt[i] > cnt[p]) p = i;
    }
    cout << p << endl;
}

