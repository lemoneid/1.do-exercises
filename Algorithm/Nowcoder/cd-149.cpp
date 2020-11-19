/*************************************************************************
	> File Name: cd-149.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 15时46分51秒
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

void output(int (*matrix)[MAX_N + 5], int ux, int uy, int dx, int dy) {
    if (ux == dx) {
        for (int i = uy; i <= dy; ++i) {
            printf("%d ", matrix[ux][i]);
        }
        return ;
    }
    if (uy == dy) {
        for (int i = ux; i <= dx; ++i) {
            printf("%d ", matrix[i][uy]);
        }
        return ;
    }
    int x = ux, y = uy;
    while (y != dy) {
        printf("%d ",matrix[ux][y++]);
    }
    while (x != dx) {
        printf("%d ", matrix[x++][dy]);
    }
    while (y != uy) {
        printf("%d ", matrix[dx][y--]);
    }
    while (x != ux) {
        printf("%d ", matrix[x--][uy]);
    }
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int ux = 0, uy = 0, dx = n - 1, dy = m - 1;
    while (ux <= dx && uy <= dy) {
        output(matrix, ux++, uy++, dx--, dy--);
    }
    printf("\n");
    return 0;
}
