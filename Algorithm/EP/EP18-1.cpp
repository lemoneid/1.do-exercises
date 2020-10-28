/*************************************************************************
	> File Name: EP18-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月26日 星期二 19时06分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 15

int arr[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5] = {0};

int dfs(int i, int j, int n) {
    if (i + 1 == n) return arr[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1, val2;
    val1 = dfs(i + 1, j, n);
    val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = max(val1, val2) + arr[i][j];
}

int main() {
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << dfs(0, 0, max_n) << endl;
    return 0;
}
