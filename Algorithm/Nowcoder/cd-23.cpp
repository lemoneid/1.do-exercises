/*************************************************************************
	> File Name: cd-23.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 20 Sep 2020 09:25:50 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define swap(a, b)  {\
    __typeof(a) _temp = a;\
    a = b; b = _temp;\
}
const int MAX_N  = 1e5;
int arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int a = 1, b = 2;
    for (int i = 1; i <= n; ++i) {
        while (arr[i] != i) {
            int id = arr[i];
            swap(arr[i], arr[id]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        cout << arr[i];
    }
    return 0;
}
