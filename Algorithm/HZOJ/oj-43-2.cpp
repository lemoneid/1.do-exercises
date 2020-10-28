/*************************************************************************
	> File Name: oj-43-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月28日 星期四 18时15分57秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n 1000

int arr[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5] = {0};
int dfs(int i, int j, int n) {
    if (i == n - 1) return arr[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = arr[i][j] + max(val1, val2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}
