/*************************************************************************
	> File Name: oj-287.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 08时37分39秒
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


struct cmp {
    bool operator()(int &a, int &b) {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> que;

int main() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        que.push(x);
    }
    int ans = 0;
    while (que.size() > 1) {
        int x = que.top();
        que.pop();
        int y = que.top();
        que.pop();
        ans += x + y;
        que.push(x + y);
    }
    cout << ans << endl;
    return 0;
}
