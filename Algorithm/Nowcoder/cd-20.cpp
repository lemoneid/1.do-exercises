/*************************************************************************
	> File Name: cd-20.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 11时54分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define MAX_N 500
int arr[MAX_N + 5];
int n;
#define ind(x, y) (x + 500 * y)
unordered_map<int, int>s;

int process(int *arr,int l, int r) {
    if (l == r) return arr[l - 1] * arr[l] * arr[l + 1];
    if (s[ind(l, r)]) {
        return s[ind(l, r)];
    }
    int ans = max(arr[l - 1] * arr[l] * arr[r + 1] + process(arr, l + 1, r),
                  arr[r] * arr[l - 1] * arr[r + 1] + process(arr, l, r - 1));
    for (int i = l + 1; i < r; ++i) {
        ans = max(ans, arr[i] * arr[l  - 1] * arr[r + 1] + process(arr, l, i - 1) + process(arr, i + 1, r));
    }
    s[ind(l, r)] = ans;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    arr[0] = arr[n + 1] = 1;
    cout << process(arr, 1, n) << endl;
    return 0;
}
