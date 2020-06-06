/*************************************************************************
	> File Name: EP39.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月02日 星期二 20时41分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int is_val(int k) {
    int sum;
    int cnt = 0;
    for (int n = 1; n < 40; ++n) {
        for (int m = n + 1; ; ++m) {
            if (gcd(n, m) - 1) continue;
            sum = 2 * n * m + m * m - n * n + m * m + n * n;
            if (k % sum == 0) ++cnt;
            if (sum > k) break;
        }
    }
    return cnt;
}

int main() {
    int cnt = 0, x;
    for (int k = 3; k <= 1000; ++k) {
        int temp = is_val(k);
        if (temp > cnt) {
            cnt = temp;
            x = k;        
        }
    }
    cout << x << " " << cnt << endl;
    return 0;
}
