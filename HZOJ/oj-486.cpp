/*************************************************************************
> File Name: oj-486.cpp
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月11日 星期二 22时05分15秒
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005] = {0, 1, 3};
int n;

int main() {
    cin >> n;
    for (int i = 3; i <= n; ++i) {
        arr[i] = arr[i - 1] + 2 * arr[i - 2];
        arr[i] %= 12345;
    }
    cout << arr[n] << endl;
    return 0;
}
