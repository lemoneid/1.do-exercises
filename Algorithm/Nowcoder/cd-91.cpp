/*************************************************************************
	> File Name: cd-91.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 20时47分38秒
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
#define MAX_N 5000
int arr[MAX_N + 5];
int f[MAX_N + 5][MAX_N + 5], s[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int j = 0; j < n; ++j) {
        f[j][j] = arr[j];
        for (int i = j - 1; i >= 0; --i) {
            f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);
            s[i][j] = min(f[i + 1][j], f[i][j - 1]);
        }
    }
    cout << max(f[0][n - 1], s[0][n - 1]) << endl;
    return 0;
}
