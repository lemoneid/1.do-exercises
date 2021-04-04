/*************************************************************************
	> File Name: oj-508.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 20时39分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAX_N = 1000;
int arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    int x, y;
    n -= 1;
    while (1) {
        switch (n) {
            case 0 : ans += arr[0], n = -1; break;
            case 1 : ans += arr[1], n = -1; break;
            case 2 : ans += arr[0] + arr[1] + arr[2], n = -1; break;
            default : {
                x = arr[1] + arr[0] + arr[n] + arr[1];
                y = arr[n] + arr[0] + arr[n - 1] + arr[0];
                ans += min(x, y);
                n -= 2;
            } break;
        }
        if (n < 0) break;
    }
    cout << ans << endl;
    return 0;
}
