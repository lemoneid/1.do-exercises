/*************************************************************************
	> File Name: 151.之字形打印矩阵.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Mon 21 Sep 2020 06:05:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N  200
int n, m;
int arr[MAX_N + 5][MAX_N + 5];
int x1, y1, x2, y2;

void print(int flag) {

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << arr[0][0];
    int flag = 1;
    while (1) {
        if (x1 < n) x1++;
        else y1++;
        if (y2 < m) y2++;
        else x2++;
        if (x1 == x2 && y1 == y2) break;
        print(flag);
        flag *= -1;
    }
    return 0;
}
