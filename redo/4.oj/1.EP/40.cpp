/*************************************************************************
	> File Name: 40.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 19时34分24秒
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
int f[10];

void init() {
    for (int i = 1; i < 8; i++) {
        f[i] = 9 * pow(10, i - 1) * i + f[i - 1];
    } 
}

int calc(int n) {
    int h = 0;
    while (f[h] < n) h++;
    if (h <= 1) return n;
    int x = pow(10, h - 1) + (n - f[h - 1]) / h;
    int y = (n - f[h - 1]) % h;
    if (y == 0) return 9;
    int ans = (x / pow(10, h - y));
    ans %= 10;
    return ans;
} 

int main() {
    init();
    int ans = 1;
    for (int i = 0; i < 7; ++i) {
        ans *= calc(pow(10, i));
    }
    cout << ans << endl;
    return 0;
}
