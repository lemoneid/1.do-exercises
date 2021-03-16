/*************************************************************************
	> File Name: 11.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 14时05分06秒
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
using namespace std;
#define MAX_N 20 
int arr[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 1, 1, 1, -1};

int calc(int x, int y) {
    int ans = 0, p, flag;
    for (int i = 0; i < 4; i++) {
        p = 1;
        flag = 1;
        for (int j = 0; j < 4; j++) {
            int xx = x + dir[j][0];
            int yy = y + dir[j][1];
            if (xx < 0 || x >= MAX_N || y < 0 || yy >= MAX_N) break;
            flag = 0;
            p *= arr[xx][yy];
        }
        if (flag && p > ans) ans = p;
    }
    return ans;
}

int main() {
    int n = 20;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < n - 3; j++) {
            int p = calc(i, j);
            ans = max(ans, p);
        }
    }
    cout << ans << endl;
    return 0;
}
