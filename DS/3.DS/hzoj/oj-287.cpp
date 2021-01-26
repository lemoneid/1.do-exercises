/*************************************************************************
	> File Name: oj-287.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月21日 星期四 23时59分09秒
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
#define MAX_N 10000
int a[MAX_N + 5];

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int> > heap;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        heap.push(x);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int x = heap.top();
        heap.pop();
        x += heap.top();
        heap.pop();
        heap.push(x);
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
