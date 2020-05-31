/*************************************************************************
	> File Name: EP35.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月30日 星期六 18时35分27秒
 ************************************************************************/

#include <iostream> 
#include <cmath>
#include <algorithm>
using namespace std;
#define max_n 1000000

int digits(int x) {
    if (x == 0) return 1;
    return (floor(log10(x)) + 1);
}

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

int init() {
    for (int i = 2; i < max_n; ++i) {
        if(!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int x, cnt = 0;
    for (int i = 1; i <= prime[0]; ++i) {
        x = prime[i];
        int flag = 1;
        int num = digits(x);
        int temp = pow(10, num - 1);
        for(int j = 0; j < num; ++j) {
            x = x % temp * 10 + x / temp;
            if(is_prime[x]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cnt += 1; 
        }
    }
    cout << cnt << endl;
    return 0;
}
