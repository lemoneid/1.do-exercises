/*************************************************************************
	> File Name: oj-521.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月22日 星期四 20时47分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int n, m, num[35], ans, p[3000005], check[3000005];

void init() {
    p[1] = 1;
    for (int i = 2; i * i <= 3000000; ++i) {
        if (p[i] == 0) p[p[0]++] = i;
        for (int j = 1; j <= p[0] && i * p[j] <= 3000000; ++j) {
            p[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
    return ;
}

void func(int s, int left, int sum) {
    if (left == 0) {
        if (p[sum] == 0) ans++;
        return ;
    }
    for (int i = s; i < n - left + 1; ++i) {
        func(i + 1, left - 1, sum + num[i]);
    }
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    func(0, m, 0);
    cout << ans << endl;

    return 0;
}
