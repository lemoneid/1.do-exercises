/*************************************************************************
	> File Name: oj-82.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 02 Sep 2020 11:21:50 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 2;
unsigned int n, m;
int num[MAXN];

int check(int x) {
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (num[i] > x) ans += num[i] - x;
        else break;
        if (ans >= m) return 1;
    }
    return (ans >= m);
}

int main() {
    cin >> n >> m;
    int r = 0, l = 0 , mid;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    r = num[n - 1];
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;

    return 0;
}
