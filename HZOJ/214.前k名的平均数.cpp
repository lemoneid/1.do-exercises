/*************************************************************************
	> File Name: 214.前k名的平均数.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 19时44分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, arr[35] = {0}, k;
    double sum;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    cin >> k;
    for (int i = 0; i < k; ++i)
        sum += arr[i];
    printf("%.2f\n", sum  * 1.0 / k);
    return 0;
}

