/*************************************************************************
	> File Name: cd-141.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 18时29分40秒
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
#define MAX_N 100000
int arr[MAX_N + 5], n, eor[MAX_N + 5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    eor[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        eor[i] = eor[i - 1] ^ arr[i];
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <= j; ++i) {
            ans = max(ans, i == 0 ? eor[j] : eor[j] ^ eor[i - 1]);
        }
    }
    cout << ans << endl;

    return 0;
}
