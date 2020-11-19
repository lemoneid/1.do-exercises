/*************************************************************************
	> File Name: cd-89.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 20时15分01秒
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
long long arr[MAX_N + 5];
int n, k;
long long l, r;

inline int calc(long long x) {
    long long sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > x) return 0;
        if (sum + arr[i] > x) {
            sum = arr[i];
            cnt++;
        } else {
            sum += arr[i];
        }
    }
    cnt += sum != 0;
    return cnt <= k;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
        r += arr[i];
        if (i == 0) l = arr[i];
        else l = max(l, arr[i]);
    }
    long long mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (calc(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%lld", l);
    return 0;
}
