/*************************************************************************
	> File Name: cd-54.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 11时16分22秒
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
vector<int> h;
int n;
long long ans;
int main() {
    cin >> n;
    stack<int> stk;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        h.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && h[i] > h[stk.top()]) {
            int cur = stk.top();
            stk.pop();
            if (stk.empty()) break;
            int l = stk.top();
            int r = i;
            int hei = min(h[r], h[l]) - h[cur];
            ans +=  (long long)(r - l - 1) * hei;
        }
        stk.push(i);
    }
    cout << ans << endl;
    return 0;
}
