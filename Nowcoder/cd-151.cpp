/*************************************************************************
	> File Name: cd-151.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 20 Sep 2020 09:14:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 200
int arr[MAX_N + 5][MAX_N + 5];
int dir[2][2]{1,-1, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    int x = 0, y = 0;
    cout << arr[0][0];
    while (1) {
        
    }

    return 0;
}
