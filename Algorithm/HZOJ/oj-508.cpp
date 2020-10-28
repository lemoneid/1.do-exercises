/*************************************************************************
	> File Name: 0j-508.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 10时28分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000

int t[max_n + 5] = {0};

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t, t + n);
    while (n > 3) {
        ans += min(t[0] * 2 + t[n - 1] + t[n - 2],t[0] + t[1] *2 + t[n - 1]);
        n -= 2;
    }
    if (n == 3) ans += t[0] + t[1] + t[2];
    if (n == 2) ans += t[1];
    if (n == 1) ans += t[0];
    cout << ans << endl;
    return 0;
}
