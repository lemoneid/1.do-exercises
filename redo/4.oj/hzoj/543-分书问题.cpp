/*************************************************************************
	> File Name: 543-分书问题.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 11时11分04秒
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
const int MAX_N = 20;
int n, ans;
char matrix[MAX_N + 5][MAX_N + 5];
bool mask[MAX_N + 5];

void dfs(int start) {
    if (start == n) {
        ans++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (matrix[start][i] == '0') continue;
        if (mask[i]) continue;
        mask[i] = true;
        dfs(start + 1);
        mask[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> matrix[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}
