/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月26日 星期六 08时52分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 100000

int n, mod;
int num[MAX_N + 5];
long long ans[MAX_N + 5] = {1, 0};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> mod;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        ans[i] = ans[i - 1] * num[i] % mod;
    }
    long long res = 1;
    for (int i = n; i > 0; --i) {
        ans[i] = ans[i - 1] * res % mod;
        res = res * num[i] % mod;
    }
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        cout << ans[i];
    }
    return 0;
}
