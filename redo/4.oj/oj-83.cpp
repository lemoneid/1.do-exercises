/*************************************************************************
	> File Name: oj-83.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 20时55分31秒
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

int dfs(int cur, int sum, int left) {
    if (left == 1 || left == 0) {
        return 1;
    }
    int cnt = 0;
    for (int i = cur; i <= sum / left; i++) {
        cnt += dfs(i, sum - i, left - 1);
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n / m; i++) {
        cnt += dfs(i, n - i, m - 1);
    }
    cout << cnt << endl;
    return 0;
}
