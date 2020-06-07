/*************************************************************************
	> File Name: EP43.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月06日 星期六 16时12分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int prime[10] = {0, 2, 3, 5, 7, 11, 13, 17};
int is_val(int *a) {
    int num = 0, flag;
    for (int i = 1; i < 8; ++i) {
        num = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
        if(num % prime[i] != 0) return 0;
    }
    return 1;
}

long long calc(int *a) {
    long long sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum = sum * 10 + a[i];
    }
    return sum;
}

int main() {
    int a[10] = {0};
    long long ans = 0;
    for (int i = 0; i < 10; ++i) a[i] = i;
    do {
        if (is_val(a)) {
            ans += calc(a);
        }
    } while(next_permutation(a, a + 10));
    cout << ans << endl; 
    return 0;
}
