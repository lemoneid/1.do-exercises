/*************************************************************************
	> File Name: cd-14.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月15日 星期二 08时01分44秒
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

int arr[MAX_N + 5], help[MAX_N + 5];

int binary_search(int *arr,int n, int k) {
    int mid;
    int l  = 0, r = n + 1;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r == n + 1 ?  -1 : r;
}

int main() {

    int n, k, sum = 0;
    cin >> n >> k;
    for (int i = 1; i <=  n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        help[i] = max(arr[i], help[i - 1]);
    }
    int len = 0, res;
    for (int i = 1; i <= n; ++i) {
        int res = binary_search(help, i, arr[i] - k);
        //cout << " i " << i << " res " << res << endl;
        if (res != -1) len = max(len, i - res);
    }
    cout << len << endl;
    return 0;
}
