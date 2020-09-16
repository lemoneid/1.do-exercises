/*************************************************************************
	> File Name: oj-517.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 19时23分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n - i; ++j) {
            int k = n - i - j;
            if (k < j) break;
            if (i + j > k && k - i < j) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
