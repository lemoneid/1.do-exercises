/*************************************************************************
	> File Name: oj-240.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 12时45分07秒
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
#define MAX_N 5000
char mmap[MAX_N + 5][MAX_N + 5];
int num[10] = {0, 1};

int print(int x, int y, int n) {
    if (n == 1) {
        mmap[x][y] = 'X';
        return 0;
    }
    int len = pow(3, n - 2);
    print(x, y, n - 1);
    print(x, y + 2 * len, n - 1);
    print(x + 2 * len, y, n - 1);
    print(x + 2 * len, y + 2 * len, n - 1);
    print(x + len, y + len, n - 1);
    return 1;
}

int main() {
    print(1, 1, 7);
    int n = 0;
    while (cin >> n && n != -1) {
        for (int i = 1, I = pow(3, n - 1); i <= I; i++) {
            for (int j = 1; j <= I; j++) {
                cout << (mmap[i][j] == 'X' ? "X" : " ");
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
