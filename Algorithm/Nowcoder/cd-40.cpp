/*************************************************************************
	> File Name: cd-40.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 19时32分58秒
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
int a[MAX_N + 5];
int mmax= 0x80000000;
int mmin= 0x7fffffff;

inline int bucket(long long num, long long len, long long mmin, long long mmax) {
}

int calc(int *nums, int len, int mmax, int mmain) {
    if (mmax == mmin) return 0;
    bool *hasNum = new bool[len + 5];
    int *maxs = new int[len + 5];
    int *mins = new int[len + 5];
    int bid = 0;
    for (int i = 0; i < len; ++i) {
        bid = (int)(long long)(nums[i] - mmin) * len / (long long)(mmax - mmin);
        mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]): nums[i];
        maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]): nums[i];
        hasNum[bid] = true;
    }

    int res = 0;
    int lastMax = maxs[0];
    for (int i = 0; i <= len; ++i) {
        if (!hasNum[i]) continue;
        res = max(res, mins[i] - lastMax);
        lastMax  = maxs[i];
    }
    delete hasNum;
    delete maxs, mins;
    return res;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i); 
        mmax = max(mmax, a[i]);
        mmin = min(mmin, a[i]);
    }
    ans = calc(a, n, mmax, mmin);
    printf("%d\n", ans);
    return 0;
}
