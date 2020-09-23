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
    for (int i = 1; i <= m; ++i) {
        cin >> num[i];
        r += num[i];
    }
    while (l < r) {
        int mid = (l + r) >> 1, cnt = 0, sum  = 0;
        for (int i = 1; i <= m; ++i) {
            sum += num[i];
            if (sum > mid) {
                sum = num[i];
                cnt++;
            } else if (sum == mid) {
                sum = 0;
                cnt++;;
            }
        }
        if (sum != 0) cnt++;
        if (cnt <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int sum = 0, id = 1;
    for (int i = m; i > 0; --i) {
        sum += num[i];
        if (sum == l) {
            sum = 0;
            a[id++] = i;
        } else if (sum > l) {
            sum = num[i];
            a[id++] = i + 1;
        }
    }
    cout << "1 " << a[id - 1] - 1<< endl;
    for (int i = id - 1; i > 1; --i) {
        cout << a[i] << " " << a[i - 1] - 1 << endl;
    }
    cout << a[1] << " " << m << endl;
    return 0;
}
