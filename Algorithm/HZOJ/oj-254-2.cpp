/*************************************************************************
	> File Name: t-251.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月28日 星期三 20时06分27秒
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
#define MAX_N 50000

struct Node {
    int s, e, num, id;
} cow;

struct cmp1 {
    bool operator()(const Node &a, const Node &b) {
        if (a.s - b.s) return a.s > b.s;
        return a.id > b.id;
    }
};

struct cmp2 {
    bool operator()(const Node &a, const Node &b) {
        return a.e > b.e;
    }
};

struct cmp3 {
    bool operator()(const Node &a, const Node &b) {
        return a.num> b.num;
    }
};


priority_queue<Node, vector<Node>, cmp1> que1;
priority_queue<Node, vector<Node>, cmp2> que2;
//priority_queue<Node, vector<Node>, cmp3> que3;
priority_queue<int, vector<int>, greater<int>> que3;

int ans[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
     //   cow[i].s = a;
     //   cow[i].e = b;
        que1.push((Node){a, b, 1, i + 1});
    }
    
    int tot = 0;
    while (!que1.empty()) {
        Node temp = que1.top();
        que1.pop();
        while (!que2.empty() && que2.top().e < temp.s) {
            que3.push(que2.top().num);
            que2.pop();
        }
        if (que3.empty()) {
            tot++;
            que3.push(tot);
        }
        temp.num = que3.top();
        ans[temp.id] = temp.num;
        que3.pop();
        que2.push(temp);
        
    }
    while (!que2.empty()) que2.pop();
    cout << tot << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
