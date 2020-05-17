/*************************************************************************
	> File Name: EP46-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 19时58分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int max_n = 1000000;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            is_prime[i * prime[j]] = 1;
            if ( i % prime[j] == 0 ) break;
        }
    }
}


int func(int n) {
    return 2 * n * n;
}

int binart_search( int (*func)(int), int l, int r, int x){
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return mid;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binart_search(func, l, r, x);
}

int is_val(int n) {
    for (int i = 2; i <= prime[0] && prime[i] < n; ++i) {
        int x = n - prime[i];
        if (binart_search(func, 1, x, x)) return 1;
    }
    return 0;
}

int main() {
    init();
    for (int i = 9; ; i +=2) {
        if (!is_prime[i]) continue;
        if (is_val(i)) continue;
        cout << i << endl;
        break;
    }
    return 0;
}
