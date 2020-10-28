/*************************************************************************
	> File Name: oj-514.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 16时14分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 800 
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3 ,7, 6};

int calc(int x) {
    int cnt = 0;
    if (x == 0) return num[0];
    while (x) {
        cnt += num[x % 10];
        x /= 10;
    }
    return cnt;
}
int main() {
    int n, ans = 0;
    cin >> n;
    n -= 4;
    for (int i = 0; i <= maxn; ++i) {
        for (int j = i; j <= maxn; ++j) {
            if (calc(i) + calc(j) + calc(i + j) == n) {
                if (i == j) ans += 1;
                else ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
