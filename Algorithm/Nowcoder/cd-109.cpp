/*************************************************************************
	> File Name: cd-109.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 17时40分53秒
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
#define MAX_N 10000
int n, m;
int arr[MAX_N + 5];

inline int getNextId(int *arr, int cur) {
    int step = 0;
    if (arr[cur]) step = 1;
    while (step < m) {
        do {
            cur = (cur + 1 ) % n;
        } while (arr[cur] == 0);
        step++;
    }
    return cur;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) arr[i] = 1;
    int size = n, cur = 0;
    while (size > 1) {
        cur = getNextId(arr, cur);
        arr[cur] = 0;
        size--;
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) continue;
        cout << i + 1 << endl;
        return 0;
    }
    return 0;
}
