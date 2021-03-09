/*************************************************************************
	> File Name: string.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 21时46分31秒
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
char text[MAX_N], pattern[MAX_N];

#define TEST(func, s, t) {\
    printf("%s : %d\n", #func, func(s, t));\
}

int brute_force(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0; i < len1 - len2 + 1; i++) {
        int j = 0;
        for (j = 0; t[j]; j++) {
            if (s[i + j] - t[j]) break;
        }
        if (!t[j]) return i;
    }
    return -1;
}

int sunday(char *s, char *t) {
    int ind[128] = {0};
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0; i < 128; i++) ind[i] = len2 + 1;
    for (int i = 0; t[i]; i++) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (s[i + j] == t[j]) continue;
            i += ind[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int shift_and(char *s, char *t) {
    int code[128] = {0};
    int len = 0;
    while (t[len]) {
        code[t[len]] |= 1 << len;
        len++;
    }
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}

int kmp(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    for (int i = 0, j = -1; i < len2; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (j != -1) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (!t[j + 1]) return i - len2 + 1;
    }
    return -1;
}

int main() {
    while (cin >> text >> pattern) {
        TEST(brute_force, text, pattern);
        TEST(sunday, text, pattern);
        TEST(shift_and, text, pattern);
        TEST(kmp, text, pattern);
    }

    return 0;
}
