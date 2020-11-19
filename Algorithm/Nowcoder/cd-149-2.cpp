/*************************************************************************
	> File Name: cd-149-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 15时59分51秒
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
#define MAX_N 200
int matrix[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {}
void output(int (*matrix)[MAX_N + 5], int n, int m) {
    int tot = n * m, cur = 0, x = 0, y = 0;
    while (cur < tot) {
        while (y < )
    }

}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    output(matrix, n, m);


    return 0;
}
