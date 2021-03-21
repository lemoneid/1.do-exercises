/*************************************************************************
	> File Name: oj-391.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 13时00分45秒
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
#define MAX_N 100000
long long arr[MAX_N + 5];
int n, m;

bool check(long long x) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) return false;
        sum += arr[i];
        if (sum == x) {
            sum  = 0;
            cnt++;
        } else if (sum > x) {
            sum = arr[i];
            cnt++;
        }
    }
    cnt += sum > 0;
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    long long l = 0, r = 0; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        l = max(arr[i], l);
        r += arr[i];
    }
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;

    return 0;
}
