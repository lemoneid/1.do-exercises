/*************************************************************************
	> File Name: 147.数字出现奇数次.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月21日 星期一 20时22分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5]; 
int n;

int main() {
    int res = 0, tmp = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        res ^= arr[i];
    }
    int a = res & (~res + 1);
    int k = res & (-res);
    cout << "a = " << a << "; b = " << k << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i] & k) {
            tmp ^= arr[i];
        }
    }
    res ^= tmp;
    if (res > tmp) {
        cout << tmp  << " " << res << endl;
    } else {
        cout << res  << " " << tmp << endl;
    }
    return 0;
}
