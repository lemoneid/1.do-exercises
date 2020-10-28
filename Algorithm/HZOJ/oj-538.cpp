/*************************************************************************
	> File Name: oj-538.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月15日 星期四 18时41分38秒
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
#define MAX_N 20

int n, flag;
int mmap[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5];

void dfs(int x) {
    if (check[x] == 1) return ;
    check[x] = 1;
    if (flag) printf("-");
    flag = 1;
    cout << x;
    for (int i = 1; i <= n; ++i) {
        if (mmap[x][i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }

    return 0;
}
