/*************************************************************************
	> File Name: oj-43.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月28日 星期四 18时05分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000

int main() {
    int n, arr[max_n + 5][max_n + 5];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <=i; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] += max(arr[i + 1][j], arr[i+1][j+1]);
        }
    }
    cout << arr[0][0] <<endl;
    return 0;
}
