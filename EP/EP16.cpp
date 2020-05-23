/*************************************************************************
	> File Name: EP16.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 15时15分15秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n 301

int ans[max_n + 5] = {1, 1, 0};

int main() {
    int sum = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 1; j <= ans[0] ; ++j) {
            ans[j] *= 1024; 
        }
        for (int j = 1; j <= ans[0]; ++j) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = 1; i <= ans[0]; ++i) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}

