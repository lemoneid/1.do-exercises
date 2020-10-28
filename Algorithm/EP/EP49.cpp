/*************************************************************************
	> File Name: EP49.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月07日 星期日 23时00分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max_n 10000

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
}

int is_val(int *arr) {
    int temp = 0;
    for (int i = 0; i < 4; ++i) temp = temp * 10 + arr[i];
    return is_prime[temp] ? 0 : temp;
}

bool cmp(char a, char b) {
    return a < b;
}

int judge(int a, int b) {
    char A[5], B[5], C[5];
    sprintf(A, "%d", a);
    sprintf(B, "%d", b);
    sort(A, A + 4, cmp);
    sort(B, B + 4, cmp);
    if (strcmp(A, B) == 0)
        return 1;
    return 0;
}

int main() {
    init();
    long long ans = 0;
    int i = 1, a, b, c;
    while (prime[i++] < 1000) ++i;
    for (; i < prime[0] - 2; ++i) {
        a = prime[i];
        for( int j = i + 1; j < prime[0] - 1; ++j){ 
            b = prime[j];
            if (!judge(a, b)) continue;
            c = b * 2 - a;
            if (!judge(a, c)) continue;
            if (c < max_n && !is_prime[c]) {
                cout << a << b << c << endl;
            }
        }
    }
    return 0;
}
