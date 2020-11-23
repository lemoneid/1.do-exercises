/*************************************************************************
	> File Name: cd-154.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 21时05分42秒
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
int arr[MAX_N + 5];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    int cand = 0, times = 0, p = n / 2;
    for (int i = 0; i < n; ++i) {
        if (times == 0) {
            cand = arr[i];
            times = 1;
        } else if (arr[i] == cand) {
            times++;
        } else {
            times--;
        }
    }
    times = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == cand) times++;
    }
    cout << (times > p ? cand : -1) << endl;
    return 0;
}
