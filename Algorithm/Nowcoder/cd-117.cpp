/*************************************************************************
	> File Name: cd-117.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 13时48分01秒
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

int main() {
    int n;
    scanf("%d%s", &n, s);
    printf("%s", s + n);
    s[n] = '\0';
    printf("%s\n", s);

    return 0;
}
