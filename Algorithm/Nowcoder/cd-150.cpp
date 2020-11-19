/*************************************************************************
	> File Name: cd-150.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 16时12分47秒
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

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j != -1; --j) { 
            j != n - 1 && printf(" ");
            printf("%d", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}

