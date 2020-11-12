/*************************************************************************
	> File Name: cd-60.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 10时03分24秒
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

void process(int i, int n, bool down) {
    if (i > n) return ;
    process(i + 1, n, true);
    printf("%s\n", down ? "down" : "up");
    process(i + 1, n, false);
}


int main() {
    int n;
    scanf("%d", &n);
    process(1, n, true);
    return 0;
}
