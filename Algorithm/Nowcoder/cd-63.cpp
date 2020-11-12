/*************************************************************************
	> File Name: cd-63.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 13时05分19秒
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

int larr[MAX_N + 5], rarr[MAX_N + 5];
int arr[MAX_N + 5];
int n;

int main() {
    cin >> n;
    for (int i = 0, tag; i < n; ++i) {
        cin >> arr[i];
        if (i == 0) tag = arr[i];
        else tag = max(tag, arr[i]);
        larr[i] = tag;
    }

    for (int i = 0, j = n - 1, ltag, rtag; i < n; i++, --j) {
        if (i == 0 ) ltag = arr[i], rtag = arr[j];
        else ltag = max(ltag, arr[i]), rtag = max(rtag, arr[j]);
        larr[i] = ltag, rarr[j] = rtag;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, abs(larr[i] - rarr[i + 1]));
    }
    cout << ans << endl;

    return 0;
}

