/*************************************************************************
> File Name: oj-240.cpp
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月11日 星期二 18时15分49秒
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

char ans[5000][5000];
int num[10] = {0, 1};
int n; 

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }

    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    return ;
}

int main() {

    for (int i = 2; i < 8; ++i) {
        num[i] = num[i - 1] * 3;
    }

    func(1, 1, 7);
    while (cin >> n && n != -1) {
        for (int i = 1; i <= num[n]; ++i) {
            for (int j = 1; j <= num[n]; ++j) {
                cout << (ans[i][j] == 'X' ? "X" : " ");
            }
            cout << endl;
        }
        cout << "-" << endl; 
    }

    return 0;
}
