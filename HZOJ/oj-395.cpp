/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月24日 星期四 14时15分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 500
int m, k;
int arr[MAX_N];

int main() {
    int l = 0, r = 0;
    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }

    while (l < r) {
        int mid = (l + r) >> 1;
        int now = 0, cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (now + arr[i] == mid) {
                cnt++;
                now = 0;
            } else if (now + arr[i] > mid) {
                now = arr[i];
                cnt++;
            } else {
                now += arr[i];
            }
            if (cnt > k) break;
        }
        if (now) cnt++;
        if (cnt <= k) r = mid;
        else l = mid + 1;
    }
    int target = l, now = 0;
    int ans[MAX_N] = {0}, len = k;
    for (int i = m - 1; i >= 0; --i) {
        if (now + arr[i] == target) {
            ans[len--] = i + 1;
            now = 0;
        } else if (now + arr[i] > target) {
            ans[len--] = i + 2;
            now = arr[i];
        } else {
            now += arr[i];
        }
    }
    cout << "1 " << ans[2] - 1 << endl;
    for (int i = 2; i < k ; ++i) {
        cout << ans[i] << " " << ans[i + 1] - 1 << endl;
    }
    cout << ans[k] << " " << m << endl;
    return 0;
}
