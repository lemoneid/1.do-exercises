#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define MAX_N 300000
long long arr[MAX_N];

int main() {
    int n, m;
    long long ans = int(0x8fffffff);
    deque<int> q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && arr[i] <= arr[q.back()]) q.pop_back();
        q.push_back(i);
        ans = max(ans, arr[i] - arr[q.front()]);
        if (q.front() + m == i) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}
