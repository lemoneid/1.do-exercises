/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月04日 星期三 11时28分23秒
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

int n, m, ans;
int buff[8];

int dfs(int cur, int left, int sum) {
    if (left == 1 || left == 0) {
        return 1;
    }
    int cnt = 0;
    for (int i = cur; left > 1 && i <= sum / left; ++i) {
        cnt += dfs(i, left - 1, sum - i);
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n / m; ++i) {
        ans += dfs(i, m - 1,  n - i);
    }
    cout << ans << endl;
    return 0;
}
