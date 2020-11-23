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
#define MAX_N 500000
char text[MAX_N + 5], pattern[MAX_N + 5];
//kmp算法的核心即是计算字符串f每一个位置之前的字符串的前缀和后缀公共部分的最大长度
//当每次比较到两个字符串的字符不同时，我们就可以根据最大公共长度将字符串f向前移动(已匹配长度-最大公共长度)位，接着继续比较下一个位置。
//

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    //j 指向当前前一个字符的next[i]的值，同时也表示需要比较的下一个位置
    //如果位置i和next[i]处的两个字符相同（下标从零开始），则next[i+1]等于next[i]加1。如果两个位置的字符不相同，我们可以将长度为next[i]的字符串继续分割，获得其最大公共长度next[next[i]]，然后再和位置i的字符比较。这是因为长度为next[i]前缀和后缀都可以分割成上部的构造，如果位置next[next[i]]和位置i的字符相同，则next[i+1]就等于next[next[i]]加1。如果不相等，就可以继续分割长度为next[next[i]]的字符串，直到字符串长度为0为止
    next[0] = -1;
    for (int i = 1, j = -1; i < len2; ++i) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j]; //向前找
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    // i 指向母串，j 指向上一次匹配成功模式串的最后一个位置,
    int flag = 0;
    for (int i = 0, j = -1; s[i]; ++i) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        //t[j] 一直匹配到 s[i];
        if (t[j + 1] == 0) cout << i - len2 + 1 << " ", flag = 1;
    }
    free(next);
    if (!flag) cout << -1 << endl;
    return -1;
    
}

int main() {
    scanf("%s%s", text, pattern);
    kmp(text, pattern);
    return 0;
}
