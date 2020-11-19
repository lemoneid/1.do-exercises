/*************************************************************************
	> File Name: cd-104.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 13时25分34秒
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
#define MAX_N 400000

char s[MAX_N + 5];

int main() {
    scanf("%[^\n]s", s);
    getchar();
    for (int i = 0; s[i]; ++i) {
        if (s[i] != ' ') printf("%c", s[i]);
        else printf("%%20");
    }
    printf("\n");
    return 0;
}
