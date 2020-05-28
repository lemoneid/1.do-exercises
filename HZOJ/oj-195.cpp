/*************************************************************************
	> File Name: oj-195.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月24日 星期日 15时37分16秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n  100000

int binary_search(int *arr, int n, int value) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (arr[mid] <= value) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int m, n, arr[max_n + 5], temp, num;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &temp);
        num = binary_search(arr, n, temp);
        !i || cout << " ";
        if ( num > -1) {
            cout << arr[num]; 
        } else {
            cout << arr[0];
        }
    }
    return 0;
}
