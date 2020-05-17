/*************************************************************************
	> File Name: EP11-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 14时14分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int max_n = 20;

int grid[max_n + 5][max_n + 5] = {0};

int dir[4][2] = {
        {0, 1}, {1, 1},
        {1, 0}, {1, -1}
};


int calc(int i, int j) {
    int p, ans = 0;
    for (int k = 0; k < 4; ++k) {
        p = 1;
        for (int step = 0; step < 4; ++step) {
            int dx = i + dir[k][0] * step;
            int dy = j + dir[k][1] * step;
            if (dx < 0 || dx >= max_n || dy < 0 || dy >= max_n) break;
            p *= grid[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
}

int main() {
    int ans = 0;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            cin >> grid[i][j];
        }
    }
    int p;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            p = calc(i, j);
            if (p > ans) ans = p;
        }
    }
    cout << ans << endl;
    return 0;
}
