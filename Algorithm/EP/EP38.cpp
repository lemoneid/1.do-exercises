/*************************************************************************
	> File Name: EP38.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月30日 星期六 15时41分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define max_n 10000

int digits(long long n) {
    if (n == 0) return 1;
    return floor(log10(n) + 1);
}

long long calc(int x) {
    long long n = 1, ans = 0;
    while (digits(ans) < 9) {
        ans *= pow(10, digits(n * x));
        ans += n * x;
        n += 1;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {1,0};
    long long temp = ans;
    while (temp) {
        if (num[temp % 10]) return 0;
        num[temp % 10] = 1;
        temp /= 10;
    }
    return ans;
}

int main() {
    long long ans = 0, temp;
    for (int i = 1; i < max_n; ++i) {
        temp = calc(i);
        ans = (temp > ans ? temp : ans);
    }
    cout << ans << endl;
}
