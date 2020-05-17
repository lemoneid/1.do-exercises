/*************************************************************************
	> File Name: EP07-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 15时48分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int SIZE = 200000;
int prime[SIZE + 5] = {0};

void init() {
    for (int i = 2; i * i < SIZE; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j < SIZE; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i  < SIZE; ++i) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
}


int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}

