/*************************************************************************
	> File Name: EP10-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 19时27分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int SIZE = 2000000;
int prime[SIZE + 5] = {0};
long long sum = 0;
void  init() {
    for (int i = 2; i < SIZE; ++i) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < SIZE; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}


int main() { 
    init();
    cout << sum << endl;
    return 0;
}
