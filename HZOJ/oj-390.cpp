/*************************************************************************
	> File Name: oj-390.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 02 Sep 2020 04:03:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
long long n, m, num[MAXN];
long long mmax = 0, all = 0;

int binary_search() {
    long long l = mmax, r = all;
    while (l < r) {
        long long mid = (l + r) >> 1, sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + num[i] == mid) {
                cnt++;
                sum = 0;
            } else if (sum + num[i] > mid) {
                cnt++;
                sum = num[i];
            } else {
                sum += num[i];
            } 
        }    
        if (sum > 0) cnt++;
        if (cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        all += num[i];
        mmax = max(mmax, num[i]);
    }
    binary_search();
    return 0;
}

