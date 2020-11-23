/*************************************************************************
	> File Name: cd-50.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 21时01分38秒
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
struct Node {
    int cost, profit;
    bool operator<(const Node &b) const {
        return this->profit < b.profit;
    }
};
typedef pair<int, int> PII;
vector<PII> arr;
priority_queue<Node> que;
queue<Node> save;

int main() {
    long long n, ans, k;
    cin >> n >> ans >> k;
    arr.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second;
    }
    for (int i = 0; i < n; ++i) {
        que.push((Node){arr[i].first, arr[i].second});
    }
    while (k--) {
        while (!que.empty() && ans < que.top().cost) {
            save.push(que.top());
            que.pop();
        }
        if (que.empty()) break;
        ans += que.top().profit;
        que.pop();
        while (!save.empty()) {
            que.push(save.front());
            save.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
