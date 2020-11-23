/*************************************************************************
	> File Name: cd-29.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 18时36分34秒
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
struct Data {
    int l, w;
};

Data arr[MAX_N + 5];
int n, dp[MAX_N + 5];
bool cmp(const Data x, const Data y) {
    if (x.l - y.l) return x.l < y.l;
    //排序策略
    return x.w > y.w;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].l, &arr[i].w);
    }
    sort(arr, arr + n, cmp);
    dp[0] = arr[0].w;
    int cnt = 1;
    for (int i = 1; i < n; ++i) { 
        if (dp[cnt - 1] < arr[i].w) dp[cnt++] = arr[i].w;
        else {
             int l = 0, r = cnt - 1, mid;
             while (l < r) {
                 mid = (l + r) >> 1;
                 if (dp[mid] >= arr[i].w) {
                     r = mid; 
                 } else {
                     l = mid + 1;
                 }
             }
             dp[l] = arr[i].w;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
