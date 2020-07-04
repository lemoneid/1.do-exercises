/*************************************************************************
	> File Name: oj-489.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月02日 星期四 10时26分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 12345

int odd[1005], even[1005];

int main() {
    int x;
    cin >> x;
    odd[1] = 1, even[1] = 8;
    for (int i = 2; i <= x; i++) {
        odd[i] = (even[i - 1] + 9 * odd[i - 1]) % MOD;
        even[i] = (odd[i - 1] + 9 * even[i - 1]) % MOD;
    }
    cout << even[x];
    return 0;
}
