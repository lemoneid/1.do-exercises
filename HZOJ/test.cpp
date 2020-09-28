/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月24日 星期四 21时21分39秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#define MAXN 1005
using namespace std;

int num[MAXN][MAXN], utd[MAXN][MAXN], dtu[MAXN][MAXN], sum[MAXN][MAXN], ans1[MAXN][2], ans2[MAXN][2];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= i; ++j) {
            dtu[i][j] = num[i][j] + max(dtu[i + 1][j], dtu[i + 1][j + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            utd[i][j] = num[i][j] + max(utd[i - 1][j], utd[i - 1][j - 1]);
            sum[i][j] = dtu[i][j] + utd[i][j] - num[i][j];
        }
    }
    /*
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 2; i <= n; ++i) {
        int y1 = 0, y2 = 0;
        for (int j = 1; j <= i; ++j) {
            if (sum[i][j] > sum[i][y1]) {
                y1 = j;
            }
        }
        for (int j = 1; j <= i; ++j) {
            if (j != y1 && sum[i][j] > sum[i][y2]){
                y2 = j;
            }
        }
        ans1[i][0] = sum[i][y1];
        ans1[i][1] = y1;
        ans2[i][0] = sum[i][y2];
        ans2[i][1] = y2;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1) {
            printf("%d\n", -1);
            continue ;
        }
        if (y == ans1[x][1]) {
            printf("%d\n", ans2[x][0]);
        } else {
            printf("%d\n", ans1[x][0]);
        }
    }


    return 0;
}
