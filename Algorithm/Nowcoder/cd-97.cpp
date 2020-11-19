/*************************************************************************
	> File Name: cd-97.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 09时42分56秒
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
#define INF_MAX 0x7fffffff
#define INF_MIN 0x80000000

char s[105];

void calc(int flag, char *s, int len) {
    if (len == 0) {
        cout << 0 << endl;
        return ;
    }
    if (!(s[0] <= '9' && s[0] > '0')) {
        cout << 0 << endl;
        return ;
    }
    long long ans = s[0] - '0';
    for (int i = 1; s[i]; ++i) {
        if (!(s[i] <= '9' && s[i] >= '0')){
            cout << 0 << endl;
            return ;
        } 
        ans = ans * 10 + s[i] - '0';
    }
    if (flag) {
        cout << (ans <= INF_MIN ? ans * -1 : 0);
    } else {
        cout << (ans <= INF_MAX ? ans : 0);
    }
}

int main() {
    cin >> s;
    int len = strlen(s); 
    if (s[0] == '-') {
        calc(1, s + 1, len - 1);
    } else {
        calc(0, s, len);
    }
    return 0;
}
