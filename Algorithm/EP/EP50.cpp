/*************************************************************************
	> File Name: EP50.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月06日 星期六 14时07分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

long long sum_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            is_prime[i *prime[j]]  = 1;
            if (i % prime[j] == 0) break;
        }
    }
    sum_prime[1] = 0;
    for (int i = 2; i <= prime[0]; ++i) {
        sum_prime[i] = sum_prime[i - 1] + prime[i - 1];
    }
}
int main() {
    init();
    int cnt = 1, num = 1;
    for (int i = 1; i <= prime[0]; ++i) {
        for (int j = i + 1; j <= prime[0]; ++j) {
            int temp = sum_prime[j] - sum_prime[i];
            if (temp > prime[prime[0]]) break;
            if (!is_prime[temp] && j - i > cnt) {
                cnt = j - i;
                num = temp;
            }
        }
    }
    cout << cnt << " " << num << endl;
    return 0;
}
