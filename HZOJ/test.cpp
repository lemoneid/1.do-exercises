/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月22日 星期二 19时13分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 500

int num[MAX_N + 5];
int a[MAX_N + 5];
int main() {
    int n, m;
    int l = 0, r = 0; 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        l = max(num[i], l);
        r += num[i];
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        int sum = 0, id = m;
        for (int i = n - 1; i >= 0; --i) {
            if (sum + num[i] < mid) {
                sum += num[i];
                continue;
            }
            if (sum + num[i] == mid) {
                a[id--] = i;
                sum = 0;
            } else if (sum + num[i] > mid) {
                sum = num[i];
                a[id--] = i + 1;
            }
            if (id < 0) break;
        }
        if (sum != 0) id--;
        if (id >= 0) r = mid;
        else l = mid + 1;
    }
    for (int i = 0; i <= m; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "1" << " " << a[1];
    for (int i = 1; i < m; ++i) {
        cout << a[i] + 1 << endl << a[i + 1];
    }
    return 0;
}
