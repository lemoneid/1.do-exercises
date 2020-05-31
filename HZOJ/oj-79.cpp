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

void init() {
    for  (int i = 2; i < max_n; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int main() {
    init();
    int a, b, i = 1;
    cin >> a >> b;
    while(prime[i] < a && i <= prime[0]) ++i;
    while(prime[i] <= b && i <= prime[0]) cout << prime[i++] << endl;
    return 0;
}
