/*************************************************************************
	> File Name: 19.string.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月15日 星期四 22时18分07秒
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
#define MAX_N 1000

char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0, I = len1 - len2 + 1; i < I; ++i) {
        int j = 0;
        for (; t[j]; ++j) {
            if (t[j] == s[i + j]) continue;
            break;
        }
        if (!t[j]) return i;
    } 
    return -1;
}

int sunday(char *s, char *t) {
    int ind[126] = {0};
    int len1 = strlen(s);
    int len2 = strlen(t);
    // ind[i] = len2 ?
    for (int i = 0; i < 126; ++i) ind[i] = len2 + 1;
    for (int i = 0; t[i]; ++i) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; ++j) {
            if (t[j] == t[i + j]) continue;
            i += ind[t[i + len2]];
            flag = 0;
            break;
        }
        if (!flag) return i;
    }
    return -1;
}

int main() {
    scanf("%s%s", text, pattern);
    
    return 0;
}
