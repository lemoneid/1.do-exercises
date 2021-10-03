/*************************************************************************
	> File Name: 2431.Expedition.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年10月03日 星期日 20时00分44秒
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
#include <queue>
using namespace std;

typedef pair<int, int> PII;
vector<PII> arr;
int l, p, n;

bool cmp(const PII &a, const PII &b) {
    return a.first < b.first;
}

int solve() {
    arr[0].first = arr[0].second = 0;
    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int> que;
    int ans = 0, pos = l, tank = p;
    for (int i = n; i >= 0 ; i--){
        int d = pos - arr[i].first;
        while (tank < d) {
            if (que.empty()) {
                return -1;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = arr[i].first;
        que.push(arr[i].second);
    }
    return ans;
}

int main() {
    while (cin >> n) {
        arr.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        cin >> l >> p;
        cout << solve() << endl;
    }
    return 0;
}

