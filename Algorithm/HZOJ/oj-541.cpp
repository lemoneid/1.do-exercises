/*************************************************************************
	> File Name: oj-541.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月15日 星期四 19时38分02秒
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

int n, m;
int arr[2][20][20], ans[2][100000], cnt[2], sum;

void func(int mark, int now) {
    if (now == n) {
        ans[mark][cnt[mark]++] = sum;
        return ;
    }
    for (int i = now + 1; i <= n; ++i) {
        if (arr[mark][i][now]) {
            sum += arr[mark][i][now];
            func(mark, i);
            sum -= arr[mark][i][now];
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[0][a][b] = arr[0][b][a] = c;
        arr[1][a][b] = arr[1][b][a] = d;
    }
    func(0, 1);
    func(1, 1);
    sort(ans[0], ans[0] + cnt[0]);
    sort(ans[1], ans[1] + cnt[1]);
    int p0 = 0, p1 = 0;
    while (p0 < cnt[0] && p1 < cnt[1]) {
        if (ans[0][p0] == ans[1][p1]) {
            cout << ans[0][p0] << endl;
            return 0;
        }
        if (ans[0][p0] < ans[1][p1]) p0++;
        else p1++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
