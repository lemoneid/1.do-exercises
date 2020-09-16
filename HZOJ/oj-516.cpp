/*************************************************************************
	> File Name: oj-516.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 18时34分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

char s[100005];
int l[100005], r[100005];
int main() {
    int n, c = 0, w = 0;
    cin >> n >> s;
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
        s[i] == 'C' && c++;
        if (s[i] == 'O') l[i] = c;
        s[j] == 'W' && w++;
        if (s[j] == 'O') r[j] = w;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'O') continue;
        ans += l[i] * r[i];
    }
    cout  << ans << endl;
    return 0;
}
