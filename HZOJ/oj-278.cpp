/*************************************************************************
	> File Name: oj-278.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月16日 星期五 20时11分17秒
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
#define MAX_N 1000000
char str[MAX_N + 5];
int ans[MAX_N + 5], nxt[MAX_N + 5];

void get_next(char *str, int *next) {
    next[0] = -1;
    for (int i = 1, j = -1; str[i]; ++i) {
        while(j != -1 && str[j + 1] != str[i]) j = next[j];
        if (str[j + 1] == str[i]) j += 1;
        next[i] = j;
    }
}

int main() {
    int n;
    cin >> n >> str;
    get_next(str, nxt);
    for (int i = 0; i < n; ++i) {
        if (nxt[i] == -1 || i - nxt[i] != ans[nxt[i]]) {
            ans[i] = i + 1;
        } else {
            ans[i] = ans[nxt[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == i + 1) {
            cout << i + 1 << " " << (i + 1) / ans[i] << endl;
        }
    }
    return 0;
}
