/*************************************************************************
	> File Name: oj-264.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月23日 星期二 20时44分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define max_n 100000

long long arr[max_n + 5];
long long l[max_n + 5], r[max_n + 5];

int main() {
    long long n;
    stack<int> s;
    cin >> n;
    arr[0] = arr[n + 1] = -1;
    for (long long i =  1; i <= n; ++i) cin >> arr[i];
    s.push(0);
    for (long long i = 1; i <= n; ++i) {
        while (arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (long long i = n; i >= 1; --i) {
        while (arr[s.top()] >= arr[i]) s.pop();
        r[i] = s.top() - i;
        s.push(i);
    }
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        ans = max(ans, arr[i] * (r[i] + l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
