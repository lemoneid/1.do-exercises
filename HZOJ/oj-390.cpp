/*************************************************************************
	> File Name: oj-390.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 02 Sep 2020 04:03:06 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, num[MAXN];

int binary_search() {
    int l = 0, r = num[n - 1];
    while (l < r) {
        int mid = (l + r + 1) >> 1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += num[i] / mid;
            if (cnt >= m) {
                l = mid;
                break;
            }
        }    
        if (cnt < m) {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num, num + n);
    binary_search();
    return 0;
}

