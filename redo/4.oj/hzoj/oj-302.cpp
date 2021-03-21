/*************************************************************************
	> File Name: oj-302.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 23时00分00秒
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
#include <queue>
using namespace std;
#define MAX_N 500
int n, m;
char grid[MAX_N + 5][MAX_N +5];
int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 0};

struct Data {
    int x, y;
    int step, d;
};

int main() {
    cin >> n >> m;
    queue<Data> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') {
            }
        }
    }


    return 0;
}
