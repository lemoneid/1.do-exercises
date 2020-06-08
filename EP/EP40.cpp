/*************************************************************************
	> File Name: EP40.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月07日 星期日 16时52分41秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int num[10] = {0};

void init() {
    for (int i = 1; i < 8; ++i) {
        num[i] = num[i- 1] + pow(10, i - 1) * i * 9;
    }
    return ;
}
int calc(int n) {
    int  h = 0, x, y, ans;
    while (num[h] < n) ++h;
    if (h > 1) x = pow(10, h - 1) + (n - num[h - 1]) / h;
    else return n;
    y = (n - num[h- 1]) % h;
    if (y == 0) return 9;
    ans = (x  / pow(10, h - y) );
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
