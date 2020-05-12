/*************************************************************************
	> File Name: 9.素数筛.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月10日 星期日 18时28分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int SIZE = 100;
int prime[SIZE + 5] = {0};

void init_prime() {
    int pos = 0;
    for (int i = 2; i < SIZE; ++i) {
        if (prime[i]) continue;
        prime[i] = i;
        for (int j = i + i; j < SIZE; j += i) {
            prime[j] = i;
        }
    }
}

int main() {
    init_prime();
    for (int i = 2; i < 100; ++i) {
        cout << "prime" << i << "= "<< prime[i] << " "<< endl;
    }
    cout << endl;
    return 0;
}
