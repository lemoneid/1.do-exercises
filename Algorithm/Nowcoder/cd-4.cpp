/*************************************************************************
	> File Name: cd-4.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 20时04分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 1000

int main() {
    int arr[MAX_N + 5];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    if (n < 3) return 0;
    int i = 0;
    while (i < n - 2) {
        if (arr[i] > m / 3) break;
        while (i < n - 2 && arr[i] == arr[i + 1]) i++;
        int l = i + 1, r = n - 1, val = m - arr[i]; 
        while (l < r) {
            if (arr[l] + arr[r] < val) {
                l++;
            } else if (arr[l] + arr[r] > val) {
                r--;
            } else {
                printf("%d %d %d\n", arr[i], arr[l], arr[r]);
                l++;
                r--;
                while (l < r && arr[l] == arr[l - 1]) l++;
                while (l < r && arr[r] == arr[r + 1]) r--;
            }
        }
        i++;
    }

    return 0;
}
