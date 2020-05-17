/*************************************************************************
	> File Name: EP47-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 11时33分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int max_n = 1000000;

int prime[max_n] = {0};
int a[max_n] = {0};
void init() {
    for (int i = 2; i < max_n; ++i) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            a[i] = 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < max_n; ++j) {
            if (i % prime[j] == 0) {
                a[i * prime[j]] = a[i];
                break;
            } else {
                prime[i * prime[j]] = 1;
                a[i * prime[j]] = a[i] + 1;

            }
        }
    }
}

int main() {
    init();
    int flag = 1;
    for (int i = 2; i < max_n; ++i) {
        flag = 1;
        for (int j = 0; flag && j < 4; ++j) {
            flag = flag && a[i+j] == 4;
        }
        if (flag) {
            cout << i << endl;
            break;
        }
    }
}
