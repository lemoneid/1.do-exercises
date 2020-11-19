/*************************************************************************
	> File Name: cd-115.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 13时32分09秒
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
#define MAX_N 100000
char s[MAX_N + 5];
char ans[MAX_N + 5];
int main() {
    int cnt = 0, id = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '*') cnt++;
        else ans[id++] = s[i];
    }
    ans[id] = '\0';
    for (int i = 0; i < cnt; ++i) {
        printf("*");
    }
    printf("%s\n", ans);
    return 0;
}
