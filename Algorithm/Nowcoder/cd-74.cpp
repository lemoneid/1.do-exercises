/*************************************************************************
	> File Name: cd-74.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 16时39分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 1000000
int arr[MAX_N + 5];
int n;

int getMin(int *arr, int n) {
    int l = 0, r = n - 1, mid = 0;
    while (l < r) {
        if (l == r - 1) break;
        if (arr[l] < arr[r]) {
            return arr[l];
        }
        mid = (l + r) >> 1;
        if (arr[l] > arr[mid]) {
            r = mid;
            continue;
        } 
        if (arr[r] < arr[mid]) {
            l = mid;
            continue;
        }
        while (l < mid) {
            if (arr[l] == arr[mid]) l++;
            else if (arr[l] < arr[mid]) return arr[l];
            else  {
                r = mid;
                break;
            }
        }
    }
    return min(arr[l], arr[r]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = getMin(arr, n);
    cout << ans << endl;
    getMin(arr, n);

    return 0;
}
