/*************************************************************************
	> File Name: oj-245.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 13时11分56秒
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

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long long idx = n & 1 ? arr[n / 2] : ((arr[n / 2] + arr[n / 2 - 1]) / 2);
    long long ans = 0;
    for (auto cur : arr) {
        ans += abs(idx - cur);
    }
    cout << ans << endl;
    return 0;
}
