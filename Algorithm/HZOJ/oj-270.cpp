/*************************************************************************
	> File Name: oj-270.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月23日 星期二 19时59分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 300000

long long  s[max_n + 5]= {0};
int q[max_n + 5], head, tail;

int main() {
    int n, m;
    long long ans;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] += s[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    ans = s[1];
    for (int i = 1; i <= n; ++i)  {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[i] < s[q[tail - 1]]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
}
