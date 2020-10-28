/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include <stdlib.h>
using namespace std;

const int SIZE = 1005;
int prime[SIZE] = {0}, check[SIZE] = {0};
int p_num = 0;
void init(){
    for (int i = 2; i < SIZE; i++) {
        check[i] || (prime[p_num++] = i);
        for (int j = 0; j < p_num && i * prime[j] < SIZE; j++) {
            check[i * prime[j]] = 1;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
    return ;
}

int main() {
    init();
    for(int i = 0; i < 20; i++){
        !i || cout << " ";
        cout << prime[i];
    }
    return 0;
}
