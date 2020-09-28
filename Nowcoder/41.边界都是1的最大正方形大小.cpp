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
int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j  = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    } 

    return 0;
}
