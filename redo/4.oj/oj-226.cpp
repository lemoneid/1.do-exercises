/*************************************************************************
	> File Name: oj-226.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 21时27分30秒
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

long long quick_multi(long long a, long long b, long long p) {
    if (a < b) swap(a, b);
    long long ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

long long quick_pow(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = quick_multi(ans, a, p);
        a = quick_multi(a, a, p);
        b >>= 1;
    }
    return ans % p;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << quick_multi(a, b, p) << endl;
    return 0;
}
