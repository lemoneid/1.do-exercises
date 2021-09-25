/*************************************************************************
	> File Name: 1852.Ants.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月25日 星期六 12时01分42秒
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

const int MAX_N = 1000000;
int arr[MAX_N + 5];
int main() {
    int n, l; 
    scanf("%d", &n);
    while (scanf("%d%d", &l, &n) != EOF) {
        int mmin = 0, mmax = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
            mmin = max(mmin, min(arr[i], l - arr[i]));
            mmax = max(mmax, max(arr[i], l - arr[i]));
        }
        printf("%d %d\n", mmin, mmax);
    }

    return 0;
}
