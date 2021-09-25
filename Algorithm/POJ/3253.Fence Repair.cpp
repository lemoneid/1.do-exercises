/*************************************************************************
	> File Name: 3253.Fence Repair.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月25日 星期六 20时12分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 20000;
int arr[MAX_N + 5];
int main() {
    int n;
    long long ans = 0;
    cin >> n;
    while (n > 1) {
        int a = 0, b = 1;
        for (int i = 2; i < n; i++) {
            if (arr[i] < arr[a]) {
                b = a;
                a = i;
            } else if (arr[i] < arr[b]) {
                b = i;
            }
        }

        int t = arr[a] + arr[b];
        ans += t;
        if (a == n - 1) swap(a, b);
        arr[a] = t;
        arr[b]  = arr[n - 1];
        n--;
    }
    cout << ans << endl;
    
    return 0;
}
