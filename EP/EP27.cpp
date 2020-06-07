/*************************************************************************
	> File Name: EP27.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月07日 星期日 15时27分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    is_prime[0] = 1;
    is_prime[1] = 1;

}

int get_len(int a, int b) {
    int cnt = 2;
    for (int n = 2; ; ++n) {
        long long temp = n * n + a * n + b;
        if (temp < 0) break;
        if (is_prime[temp]) break;
        cnt += 1;
    } 
    return cnt;
}

int main() {
    init();
    int x, y, len = 0;
    for (int b = 2; b < 1000; b++) {
        if (is_prime[b]) continue;
        for (int a = -999; a < 1000; a += 2) {
            if (a + b + 1 < 0) continue;
            if (is_prime[a + b + 1]) continue;
            int temp = get_len(a, b);
            if (temp <= len) continue;
            x = a, y = b, len = temp;
        }
    }
    printf("x = %d, y = %d, len = %d\n", x, y, len);
    cout << x * y <<endl;
    return 0;
}
