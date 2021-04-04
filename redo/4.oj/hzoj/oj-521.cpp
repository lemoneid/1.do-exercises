/*************************************************************************
	> File Name: oj-521.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 22时23分48秒
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
const int MAX_N = 3000000;
int prime[MAX_N + 5];
int check[MAX_N + 5] = {1, 1};
int arr[35];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!check[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int ans = 0;
void dfs(int *arr, int start, int left, int n, int sum) {
    if (left == 0) {
        if (check[sum] == 0) ans++;
        return ;
    }
    for (int i = start; i < n - left + 1; i++) {
        sum += arr[i]; 
        dfs(arr, i + 1, left - 1, n, sum);
        sum -= arr[i];
    }
}

int main() {
    init();
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dfs(arr, 0,  r, n, 0);
    cout << ans << endl;
    return 0;
}
