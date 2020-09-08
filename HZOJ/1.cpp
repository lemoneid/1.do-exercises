/*************************************************************************
	> File Name: oj-395.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 08 Sep 2020 02:45:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int m, k;
int num[505], a[505];
int main() {
    int l = 0, r = 0, mid, cnt, sum;
    cin >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> num[i];
        r += num[i];
    }
    while (l < r) {
        mid = (l + r) >> 1, cnt = 0, sum  = 0;
        for (int i = m; i > 0; --i) {
            sum += num[i];
            if (sum > mid) {
                sum = num[i];
                a[cnt++] = i + 1;
            } else if (sum == mid) {
                sum = 0;
                a[cnt++] = i;
            }
        }
        if (sum != 0) cnt++;
        if (cnt <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << cnt << " " << k <<  endl;
    for (int i = 0; i < cnt; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}
