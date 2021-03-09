/*************************************************************************
	> File Name: 6.string.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月16日 星期二 19时52分39秒
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
char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(const char *s, const char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0; i <= len1 - len2; ++i) {
        int j = 0;
        for (; t[j]; ++j) {
            if (s[i + j] - t[j]) break;
        }
        if (!t[j]) return i;
    }
    return -1;
}

int sunday(const char *s, const char *t) {
    int ind[128] = {0};
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0; i < 128; ++i) ind[i] = len2 + 1;
    for (int i = 0; t[i]; ++i) ind[t[i]] = len2 - i;
    for (int i = 0; i <= len1 - len2; ++i) {
        int flag = 1;
        for (int j = 0; t[j]; ++j) {
            if (s[i + j] == t[j])  continue;
            i += ind[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
}

int shift_and(const char *s, const char *t) {
    int code[128] = {0};
    int len = 0;
    for (len = 0; t[len]; len++) {
        code[t[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; s[i]; ++i) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}

int kmp(const char *s, const char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    int *next = (int *)calloc(sizeof(int), len1 + 5);
    next[0] = -1;
    for (int i = 1, j = -1; i < len2; ++i) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; ++i) {
        while (j != -1 && t[j + 1] != s[i]) j = next[i];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len2 + 1;
    }
    free(next);
    return -1;
}

int main() {


    return 0;
}
