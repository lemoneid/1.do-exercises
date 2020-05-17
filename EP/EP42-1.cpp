/*************************************************************************
	> File Name: EP42-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 23时12分52秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
#include "words.txt"
using namespace std;
inline int64_t Triangle(int n) {
    return n * (n + 1) / 2;
}

int binary_search(int64_t (*func)(int), int l, int r, int x) {
    if (l > r) return 0;
    int head = l, tail = r, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        else if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int is_val(const char *str) {
    int x = 0;
    for (int i = 0; str[i]; ++i) {
        x += str[i] - 'A' + 1;
    }
    if(binary_search(Triangle, 1, x, x)) return 1;
    return 0;
}

int main() {
    int n = sizeof(str) / 100, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt +=(is_val(str[i]));
    }
    cout << cnt;
}
