/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月21日 星期四 23时19分30秒
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
#include <queue>
using namespace std;
#define MAX_M 30000
int arr[MAX_M + 5];

void mySort(int *arr, int l, int r) {
    if (l >= r) return ;
    for (int i = l; i < r; ++i) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int pre = 0;
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        mySort(arr, pre, x);
        cout << arr[i] << endl;
        pre = x - 1;
    }
    return 0;
}
