/*************************************************************************
	> File Name: cd-30.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 19时35分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 2000000
const long long mod = 1e9 + 7;
int arr[MAX_N + 5];

long long process(int *arr, int i, int from, int mid, int to) {
    if (i == -1) return 0;
    if (arr[i] != from && arr[i] != to) {
        return -1;
    }
    if (arr[i] == from) {
        return process(arr, i - 1, from, to, mid);
    } else {
        long long rest = process(arr, i - 1, mid, from, to);
        if (rest == -1) {
            return -1;
        }
        rest %= mod;
        return ((1 << i) + rest ) % mod;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    cout << process(arr, n - 1, 1, 2, 3) << endl;

    return 0;
}
