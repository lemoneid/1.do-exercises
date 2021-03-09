/*************************************************************************
	> File Name: oj-264.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 09时30分55秒
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
#define MAX_N 100000
int a[MAX_N + 5];
int s[MAX_N + 5];
int top = -1;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    s[0] = 0;
    top++;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) {
        while (top != -1 && a[s[top]] > a[i]) {
            int h = a[s[top--]];
            ans = max(ans, (long long)h * (i - s[top] - 1));
        }
        s[++top] = i;
    } 
    cout << ans << endl;

    return 0;
}
