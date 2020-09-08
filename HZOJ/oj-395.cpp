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
    int l = 0, r = 0;
    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> num[i];
        r += num[i];
    }
    while (l < r) {
        int mid = (l + r) >> 1, id = k, sum  = 0;
        for (int i = m - 1; i >= 0; --i) {
            if (sum < mid) {
                sum += num[i];
            }
            if (sum > mid) {
                a[id--] = i + 1;
                sum = num[i];
            } else if (sum == mid) {
                a[id--] = i;
                sum = 0;
            }
            if (id < 0) {
                l = mid + 1;
                break;
            }
        }
        if (sum != 0) id--;
        if (id >= 0) {
            r = mid;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << a[i] << " " << a[i + 1] - 1 << endl;
    }
    cout << a[k] << " " << m << endl;
    return 0;
}
