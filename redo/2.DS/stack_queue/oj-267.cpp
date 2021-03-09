/*************************************************************************
	> File Name: oj-267.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 13时35分28秒
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
#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];
int s[MAX_N + 5], top = -1;
int n, m;

int main() {
    char ch;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == 'R') continue;
            f[i][j] = f[i - 1][j] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        top = -1;
        for (int j = 1; j <= m + 1; j++) {
            while (top != -1 && f[i][s[top]] > f[i][j]) {
                int h = f[i][s[top]];
                top--;
                ans = max(ans, h  * (j - s[top] - 1));
            }
            s[++top] = j;
        } 
    }
    cout << ans * 3 << endl;
    return 0;
}
