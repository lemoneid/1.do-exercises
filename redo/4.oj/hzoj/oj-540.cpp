/*************************************************************************
	> File Name: oj-540.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 11时24分14秒
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
#include <unordered_map>
using namespace std;
#define MAX_N 40
long long  arr[MAX_N + 5];
long long  n, m;
long long  num[2][MAX_N + 5];
unordered_map<long long , bool> mmap[2];

void dfs(long long  s, long long  e, long long  sum, long long  k) {
    if (sum > m) return ;
    for (long long  i = s; i < e; i++) {
        sum += arr[i]; 
        if (sum > m) continue;
        if (!mmap[k][sum]) num[k][++num[k][0]] = sum;
        dfs(i + 1 , e, sum, k);
        sum -= arr[i];
    }
    return ;
}

int main() {
    while (cin >> n >> m) {
        memset(num, 0, sizeof(num));
        mmap[0].clear();
        mmap[1].clear();
        for (long long  i = 0; i < n; i++) {
            cin >> arr[i];
        } 
        long long  mid = n / 2;
        dfs(0, mid, 0, 0);
        dfs(mid, n, 0, 1);
        sort(num[0] + 1, num[0] + num[0][0]);
        num[1][++num[1][0]] = 0;
        bool ans = false;
        for (long long  i = 1; i < num[1][0]; i++) {
            long long  l = 1, r = num[0][0] - 1, target = m - num[1][i];
            while (l < r) {
                long long  mid = (l + r) >> 1;
                if (num[0][mid] == target) {
                    ans = true;
                    break;
                }
                if (num[0][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (ans) break;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 1;
}
