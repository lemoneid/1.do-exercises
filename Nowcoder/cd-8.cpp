/*************************************************************************
	> File Name: cd-8.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月14日 星期一 14时59分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];

int main() {
    int n, k, ans  = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int l = 0, r = 0, sum = arr[0];
    while (r < n) {
        if (sum == k) {
            ans = max(ans, r - l + 1);
            sum -= arr[l++];
        } else if (sum < k) {
            r++;
            if (r == n) break;
            sum += arr[r];
        } else {
            sum -= arr[l++];
        }
    }
    cout << ans << endl;
    return 0;
}
