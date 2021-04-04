/*************************************************************************
	> File Name: oj-516.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 21时37分50秒
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
const int MAX_N = 100000;
int l[MAX_N + 5], r[MAX_N + 5];
char arr[MAX_N + 5];

int main() {
    int n;
    cin >> n >> arr + 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 'C') cnt++;
        l[i] = cnt;
    }
    cnt = 0;
    for (int i = n; i > 0; i--) {
        if (arr[i] == 'W') cnt++;
        r[i] = cnt;

    }
    long long ans = 0;
    for (int i = 2; i < n; i++) {
        if (arr[i] != 'O') continue;
        ans += l[i - 1] * r[i + 1];
    }
    cout << ans << endl;
    return 0;
}
