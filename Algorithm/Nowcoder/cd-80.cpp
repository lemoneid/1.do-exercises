/*************************************************************************
	> File Name: cd-80.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 13时23分34秒
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

priority_queue<int, vector<int>, greater<int>> gque; // small
priority_queue<int, vector<int>, less<int>> lque;   // big

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0, op, x; i < n; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            if (gque.size() && gque.top() < x) {
                lque.push(gque.top()),gque.pop();
                gque.push(x);
            } else {
                lque.push(x);
            }
            while (lque.size() > gque.size() + 1) {
                gque.push(lque.top());
                lque.pop();
            }
        } else {
            int len = lque.size() + gque.size();
            if (len == 0) {
                printf("-1\n");
                continue;
            }
            if (len & 1) {
                printf("%.1lf\n", 1.0 * lque.top());
            } else {
                printf("%.1lf\n", 1.0 * (lque.top() + gque.top()) / 2);
            }
        }
    }

    return 0;
}
