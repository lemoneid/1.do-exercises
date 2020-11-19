/*************************************************************************
	> File Name: cd-116.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 13时37分54秒
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

char s[100005];

inline void handle(char *str, int l, int r) {
}

int main() {
    scanf("%[^\n]s", s);
    int l = 0, r = 0, i = 0;
    while (s[i]) {
        while (s[i] && s[i] == ' ') i++;
        l = i;
        while (s[i] && s[i] != ' ') i++;
        r = i - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
    printf("%s", s);
    return 0;
}
