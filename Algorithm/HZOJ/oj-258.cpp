/*************************************************************************
	> File Name: oj-258.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月02日 星期四 08时21分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int arr[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }
    }
    int ans = 0x80000000;
    for (int i = 1; i <= n; ++i) {
        for (int j = i;  j <= n; ++j) {
            int pre = 0, sum = 0, temp, val = 0x80000000;
            for (int  k = 1; k <= n; ++k) {
                sum += arr[j][k] - arr[i - 1][k];
                val = max(val, sum - pre);
                pre = min(pre, sum);
            }
            ans = max(ans, val);
        }
    }
    cout << ans << endl;

    return 0;
}
