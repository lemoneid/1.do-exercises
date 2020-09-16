/*************************************************************************
	> File Name: oj-394.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 08 Sep 2020 10:47:36 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int len, n, m;
int d[50005];

void binary_search() {
    int l = 0, r = len;
    while (l < r) {
        int mid = (l + r + 1) >> 1, cnt = 0, pre = 0;
        for (int i = 1; i <= n + 1; ++i) {
            if (d[i] - d[pre] < mid) {
                cnt++;
            } else {
                pre = i;
            }
        }
        if (cnt <= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}

int main() {
    cin >> len >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    d[0] = 0, d[n + 1] = len;
    binary_search();
    return 0;
}
