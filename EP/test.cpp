#include<iostream>
#include<string.h>
using namespace std;
const int max_n = 100;

int prime[max_n] = {0};

void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++i) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    for(int i = 1; i <= prime[0]; ++i) {
        printf("the %d prime = %d\n", i, prime[i]);
    }
    return 0;
}
