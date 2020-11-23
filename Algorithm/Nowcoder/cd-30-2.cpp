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
const int mod = 1e9 + 7;
int arr[MAX_N + 5];
int sys[MAX_N + 5];
long long process(int *arr, int i, int from, int mid, int to) {
    int tmp = 0;
    long long res = 0;
    while (i >= 0) {
        if (arr[i] != from && arr[i] != to) {
            return -1;
        }
        if (arr[i] == to) {
            res = (res + sys[i]) % mod;
            swap(mid, from);
        } else {
            swap(mid, to);
        }
        i--;
    }
    return res % mod;
}

int main() {
    int n, x = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    for (int i = 0; i < n; ++i) {
        sys[i] = x;
        x = (x << 1) % mod;
    }
    cout << process(arr, n - 1, 1, 2, 3) << endl;

    return 0;
}
