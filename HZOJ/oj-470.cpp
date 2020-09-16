/*************************************************************************
	> File Name: oj-470.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月13日 星期四 18时58分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char to_10[128];
int num[500005];

void init() {
    int x = 0;
    for (int i = '0'; i <= '9'; ++i) {
        to_10[i] = x++;
    }

    for (int i = 'A'; i <= 'Z'; ++i) {
        to_10[i] = x++;
    }
    return ;
}

int main() {
    init();
    int cnt = 0, ans = 0, tmp = 0;
    string s;
    while (cin >> s) {
        for (int i = 0; i < 5; ++i) {
            num[cnt] = num[cnt] * 36 + to_10[s[i]];
        }
        cnt++;
    }
    sort(num, num + cnt);
    ans = num[1] - num[0];
    for (int i = 2; i < cnt; ++i) {
        tmp = num[i] - num[i - 1];
        if (tmp < ans) ans = tmp;
    }

    cout << ans << endl;
    return 0;
}
