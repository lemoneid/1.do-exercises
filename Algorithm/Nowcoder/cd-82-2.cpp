/*************************************************************************
	> File Name: cd-82-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 15时30分07秒
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
int arr1[MAX_N + 5], arr2[MAX_N + 5];
int len1, len2, kth;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> len1 >> len2 >> kth;
    for (int i = 0; i < len1; ++i) cin >> arr1[i];
    for (int i = 0; i < len2; ++i) cin >> arr2[i];
    if (kth < 1 || kth > len1 + len2) return 0;
    int id = 0, ans, x = 0, y = 0;
    while (id < kth) {
        if (x == len1 || y <= len1 && arr2[y] < arr1[x]) {
            ans = arr2[y++];
            id++;
        } else {
            ans  = arr1[x++];
            id++;
        }
    }
    cout << ans << endl;
    return 0;
}

