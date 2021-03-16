/*************************************************************************
	> File Name: oj-270.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 21时37分11秒
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
#define MAX_N 300000
int arr[MAX_N + 5];
int que[MAX_N + 5];
int head, tail;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = 0;
    tail = -1;
    int ans = 0;
    que[++tail] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail >= head && arr[i] <= arr[que[tail]]) tail--;
        que[++tail] = i;
        ans = max(ans, arr[i] - arr[que[head]]);
        if (que[head] + m == i) head++;
    }
    cout << ans << endl;
    return 0;
}
