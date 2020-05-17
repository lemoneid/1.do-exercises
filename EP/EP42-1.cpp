/*************************************************************************
	> File Name: EP42-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 23时12分52秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

char str[16347];

int64_t Triangle(int n) {
    return n * (n + 1) / 2;
}

int64_t str_to_sum(char *str) {
    int64_t i = 0, sum = 0;
    while(str[i]){
        sum += Triangle(str[i] - '0');
    } 
}

int binary_search(int64_t (*func)(int), int l, int r, int x) {
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return mid;
    else if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int is_val(int64_t x) {
    if(binary_search(Triangle, 1, 40, x)) return 1;
    return 0;
}

int main() {
    int cnt = 0;
    while("%s", str)) {
        cout << str;
        if (is_val(str_to_sum(str))) cnt++;
    }
    cout << cnt;
}
