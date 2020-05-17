/*************************************************************************
	> File Name: EP10-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 17时07分57秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;
const int max_n  = 1000000;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; ++i) {
        if (prime[i]) continue;
        for (int j = i; j < max_n; j += i) {
            prime[j] += 1; 
        }
    }
    return ;
}

int main () {
    int flag;
    init();
    for (int i = 2; ; ++i) {
        flag = 1;
        for (int j = 0; flag && j < 4; j++) {
            flag = flag && (prime[i + j] == 4);
        }
        if (!flag) continue;
        cout << i << endl;
        break;
    }
    return 0;
}
