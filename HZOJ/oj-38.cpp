/*************************************************************************
	> File Name: oj-38.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 20 Aug 2020 05:34:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define SIZE 1000
int num[3][SIZE + 5] = {{1, 1}, {1, 2}, {1, 3}};
int k;
int main() {
    cin >> k;
    int n = 2;
    while (n < k) {
        ++n;
        int *a = num[n % 3], *b = num[(n - 1) % 3], *c = num[(n - 2) % 3];

        for (int i = 1; i <= b[0]; ++i) {
            a[i] = b[i] + c[i];
        }
        
        a[0] = b[0];
        for (int i = 1; i <= a[0]; ++i) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }

    int *p = num[(k -1) % 3];
    for (int i = p[0]; i > 0; --i) {
        cout << p[i];
    }
    cout << endl;
    return 0;
}
