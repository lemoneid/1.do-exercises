/*************************************************************************
	> File Name: 24.奇数下标都是奇数或者偶数下标都是偶数.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 20 Sep 2020 09:41:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
const int MAXN = 1e5;
#define swap(a, b) {\
    __typeof(a) _temp = a;\
    a = b; b = _temp;\
}
int arr[MAXN +5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int x = n - n % 2;
    for (int i = 1; i <= n; i += 2) {
        if (i & 1 && arr[i] & 1) {
            continue ;
        }
        while ((arr[x] & 1) && x > 0) {
            x -= 2;
        }
        swap(arr[i], arr[x]);
    }
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        cout << arr[i];
    }
    return 0;
}
