/*************************************************************************
	> File Name: oj-79.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月28日 星期四 22时59分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 10000000;
int prime[max_n + 5] = {0};

void init(int k) {
    for  (int i = 2; i < k; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < k; ++j) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int main() {
    int a, b, i = 1;
    scanf("%d%d", &a, &b);
    init(b);
    while(prime[i] < a && i <= prime[0]) ++i;
    while(prime[i] <= b && i <= prime[0]) printf("%d\n", prime[i++]);
    return 0;
}
