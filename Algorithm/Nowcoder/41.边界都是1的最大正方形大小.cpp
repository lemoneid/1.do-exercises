/*************************************************************************
	> File Name: 41.边界都是1的最大正方形大小.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月26日 星期六 18时31分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 200

int matrix[MAX_N + 5][MAX_N + 5];
int rightt[MAX_N + 5][MAX_N + 5], down[MAX_N + 5][MAX_N + 5];
int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j  = 1; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    } 
    for (int i = n; i > 0; --i) {
        for (int j = n; j > 0; --j) {
            if (matrix[i][j] == 0) {
                rightt[i][j] = 0;
                down[i][j] = 0;
            } else{
                rightt[i][j] = rightt[i][j + 1] + 1;
                down[i][j] = down[i + 1][j] + 1;
            }
        }
    }
    int ans = 0;
    int size = n;
    while (size) {
        for (int i = 1; i <= n - size + 1; ++i) {
            for (int j = 1; j <= n - size + 1; ++j) {
                if (rightt[i][j] >= size && down[i][j] >= size 
                    && rightt[i + size - 1][j] >= size && down[i][j + size - 1] >= size) {
                        cout << size << endl;
                        return 0;
                }
            }
        }
        size--;
    }
    cout << 0 << endl;
    return 0;
}
