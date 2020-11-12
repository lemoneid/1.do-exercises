/*************************************************************************
	> File Name: P1364.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月10日 星期二 20时42分17秒
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
#define MAX_N 100

int matrix[MAX_N + 5][MAX_N + 5];
int arr[MAX_N + 5];
int n;
int main() {
    memset(matrix, 0x3f, sizeof(matrix));
    cin >> n;
    for (int i = 1, a, b, c; i <= n; ++i) {
        matrix[i][i] = 0;
        cin >> a >> b >> c;
        arr[i] = a;
        if (b > 0) matrix[i][b] = matrix[b][i] = 1;
        if (c > 0) matrix[i][c] = matrix[c][i] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    int ans;
    for (int i = 1; i <= n; ++i) {
        int tot = 0;
        for (int j = 1; j <= n; ++j) {
            tot += matrix[i][j] * arr[j];
        }
        if (i == 1) ans = tot;
        else ans = min(ans, tot);
    }
    cout << ans << endl;
    return 0;
}
