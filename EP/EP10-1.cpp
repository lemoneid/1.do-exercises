/*************************************************************************
	> File Name: EP10-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 17时07分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int SIZE = 2000000;
int prime[SIZE + 5] = {0};

long long init() {
    for (int i = 2; i * i < SIZE; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j < SIZE; j += i) {
            prime[j] = 1;
        }
    }
    long long sum = 0;
    for (int i = 2; i < SIZE; ++i) {
        if(prime[i]) continue;
        sum += i;
    }
    return sum;
}

int main () {
    cout << (init()) << endl;
    return 0;
}
