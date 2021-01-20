#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
using namespace std;
const int MAX_N = 100000;
long long arr[MAX_N + 5];

int main() {
    long long n, ans = 0;
    stack<int> stk;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    stk.push(0);
    for (int i = 1; i <= n + 1; ++i) {
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            long long h = arr[stk.top()];
            stk.pop();
            ans = max(ans, h * (i - stk.top() - 1));
        }
        stk.push(i);
    }
    cout << ans << endl;
    return 0;
}

