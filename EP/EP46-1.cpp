/*************************************************************************
	> File Name: EP10-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 17时07分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int SIZE = 200000;
int prime[SIZE + 5] = {0};
int check[SIZE] = {0};
int num;
void init() {
    for (int i = 2; i * i < SIZE; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j < SIZE; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i < SIZE; ++i) {
        if(prime[i]) continue;
        prime[++prime[0]] = i;
    }
}

void f() {
    for (int i = 2; i < prime[0]; ++i) {
        int x = 0;
        while( prime[i] + 2 * x * x < SIZE) {
            check[prime[i] + 2 * x *x] = 1;
            ++x;
        }
    }
}


int main () {
    init();
    f();
    int i = 9;
    for (; i < SIZE; i += 2) {
        if(check[i]) continue;
        break;
    }
    cout << i << endl;
    return 0;
}
