/*************************************************************************
	> File Name: cd-173.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 13时50分15秒
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
#define MAX_N 500000
int arr[MAX_N + 5];

bool process(int *arr, int l, int r) {
    if (l == r) {
        return true;
    }
    int lend = -1, rstart = r;
    for (int i = l; i < r; ++i) {
        if (arr[i] < arr[r]) {
            lend = i;
        } else {
            rstart = (rstart == r ? i : rstart);
        }
    }
    if (lend == -1 || rstart == r) {
        return process(arr, l, r - 1);
    }
    if (lend != rstart - 1) return false;
    return process(arr, l, lend) && process(arr, rstart, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    bool ans = process(arr, 0, n - 1);
    printf("%s\n", ans ? "true" : "false");
    return 0;
}
