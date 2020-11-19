/*************************************************************************
	> File Name: cd-93.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 21时27分11秒
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 1, ans = 1, x = 0;
    while (++x < n) {
        if (arr[x] == arr[x - 1] + 1) {
            cnt++;
        } else if (arr[x] == arr[x - 1]){
            continue;
        } else {
            cnt = 1;
        }
        ans = max(cnt, ans);
    }
    cout << ans << endl;
    return 0;
}
