/*************************************************************************
	> File Name: oj-389.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 02 Sep 2020 03:39:54 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int num[100005];

void binary_search() {
    int l = 1, r = num[m - 1];
    while (l < r) {
        int mid = (l + r + 1) >> 1, pre = 0, cnt = 1;
        for (int i = 1; i < m; ++i) {
            if (num[i] - num[pre] >= mid) {
                pre = i;
                cnt++;
            }
            if (cnt >= n) {
                l = mid;
                break;
            }
        }
        if (cnt < n) {
            r = mid - 1;
        }
    }
    cout << l << endl;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> num[i];
    }
    sort(num, num + m);
    binary_search(); 

    return 0;
}
