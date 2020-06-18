/*************************************************************************
	> File Name: oj-534.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月31日 星期日 16时23分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int num[25], check[1005] = {1}, ans;

void dfs(int s, int sum, int n) {
    if (check[sum] == 0) {
        ans += 1;
        check[sum] = 1;
    }
    for (int i = s; i < n; ++i) {
        sum += num[i];
        dfs(i + 1, sum, n);
        sum -= num[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    dfs(0, 0, n);
    cout << ans << endl;
    return 0;
}
