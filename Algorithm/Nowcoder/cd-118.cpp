/*************************************************************************
	> File Name: cd-118.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 13时51分33秒
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
int arr[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    for (int i = 0, j = n / 2; j < n; i++, j++) {
        i && printf(" ");
        printf("%d %d", arr[j], arr[i]);
    }
    printf("\n");
    return 0;
}
