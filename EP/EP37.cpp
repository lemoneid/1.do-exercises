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

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1,1,0};

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

bool is_val(int n) {
    int x = n, digit = floor(log10(n)) + 1;
    int h = pow(10, digit - 1);
    for (int i = 0; i < digit - 1; ++i){
        x /= 10;
        if (is_prime[x]) return false;
    }
    x = n;
    for (int i = 0; i < digit - 1; ++i){
        x %= h;
        h /= 10;
        if (is_prime[x]) return false;
    }
    return true;
}

int main() {
    init();
    int cnt = 0;
    long long sum = 0;
    for (int i = 5; i <= prime[0] && cnt < 11; ++i) {
        if (is_val(prime[i]) == false) continue; 
        cout << prime[i] << endl;
        sum += prime[i];
        cnt++;
    }
    cout << cnt << endl;
    cout << sum << endl;
    return 0;
}
