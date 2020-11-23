/*************************************************************************
	> File Name: cd-84.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 20时56分26秒
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

typedef pair<string, int> PII;

struct cmp {
    bool operator() (const PII &x, const PII &y) {
        if (x.second - y.second) return x.second > y.second;
        return x.first < y.first;
    }
};

priority_queue<PII, vector<PII>, cmp> que;
map<string, int> rec;
string s;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        rec[s]++;
    }
    for (auto &cur : rec) {
        if (que.size() == k) {
            if ((que.top().second == cur.second && cur.first < que.top().first )|| (que.top().second != cur.second && que.top().second < cur.second)) {
                que.pop();
                que.push(cur);
            }
        } else {
            que.push(cur);
        } 
    }
    vector<PII> res;
    while (que.size()) {
        res.push_back(que.top());
        que.pop();
    }
    for (auto iter = res.rbegin(); iter != res.rend(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
