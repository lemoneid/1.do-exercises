/*************************************************************************
	> File Name: EP44.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 17时51分11秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <inttypes.h>
using namespace std;

const int max_n = 10000;

int P[max_n] = {0};
int pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

void init() {
    for (int i = 1; i < max_n; ++i) {
        P[i] = pentagonal(i);
    }
}

int binary_search(int (*func)(int), int l, int r, int x) {
    int head = l, tail = r, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int is_val(int i, int j) {
    int temp = abs(P[i] - P[j]);
    int f1 = binary_search(pentagonal, 1, max_n, P[i] + P[j]);
    int f2 = binary_search(pentagonal, 1, max_n, temp);
    if ( f1 && f2 ) return temp;
    return -1;
}

int main() {
    int ans = INT32_MAX;
    init();
    for (int i = 1; i < max_n; ++i) {
        for (int j = 1; j < max_n; ++j) {
            int temp = is_val(i, j);
            if (temp != -1 && temp < ans) {
                ans =temp; 
                cout << P[i] << " and " << P[j] << " = " <<ans << endl;
                return 0; 
            }
        }
    }
    return 0;
}
