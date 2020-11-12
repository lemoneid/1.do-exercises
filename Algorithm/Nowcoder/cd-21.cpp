/*************************************************************************
	> File Name: cd-21.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 11时04分59秒
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
#define MAX_N 100000
int arr[MAX_N + 5];
int n;

long long int merge(int *arr, int l, int mid, int r) {
    int x = l, y = mid + 1;
    int *s = (int *)malloc(sizeof(int) * (r - l + 1));
    int id = 0;
    long long ans = 0;
    while (x <= mid && y <= r) {
        if (arr[x] <= arr[y]) {
            ans += arr[x] * (r - y + 1);
            s[id++] = arr[x++];
        } else {
            s[id++] = arr[y++];
        }
    }
    while (x <= mid || y <= r) {
        s[id++] = x > mid ? arr[y++] : arr[x++];
    }
    memcpy(arr + l, s, sizeof(int) * (r - l + 1));
    return ans;
}

long long func(int *arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    return func(arr, l, mid) + func(arr, mid + 1, r) + merge(arr, l, mid, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    long long ans = func(arr, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}
