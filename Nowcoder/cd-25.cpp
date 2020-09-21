/*************************************************************************
	> File Name: cd-25.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 09:26:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5], dp[MAX_N + 5];

int binary_search(int *arr, int len, int k) {E8
    int l = 0, r = len, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] > k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, len = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[len] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (dp[len] < arr[i]) {
            dp[++len] = arr[i];
        } else {
            dp[binary_search(dp, len, arr[i])] = arr[i];
        }
    }
    for (int i = 0; i <= len; ++i) {
        i && cout << " ";
        cout << dp[i];
    }
    cout << endl;
    return 0;
}
