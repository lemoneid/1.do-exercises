/*************************************************************************
	> File Name: cd-188.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 22时35分33秒
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
#define MAX_N 1000000
int arr[MAX_N + 5];
int l[MAX_N + 5], r[MAX_N + 5];
int n;

int main() {
    stack<int> stk;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i); 
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();
        l[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();
        r[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n",l[i], r[i]);
    }

    return 0;
}

