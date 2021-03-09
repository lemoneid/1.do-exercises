/*************************************************************************
	> File Name: oj-268.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 13时46分51秒
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
#include <queue>
#include <map>
using namespace std;
#define MAX_N 1000

map<int, int> q_ind;
queue<int> main_q;
queue<int> q[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1, m; i <= n; i++) {
        cin >> m;
        for (int j = 1, a; j <= m; j++) {
            cin >> a;
            q_ind[a] = i;
        }
    }
    string op;
    while (cin >> op) {
        if (op == "STOP") break;
        if (op == "ENQUEUE") {
            int x;
            cin >> x;
            q[q_ind[x]].push(x);
            if (q[q_ind[x]].size() == 1) {
                main_q.push(q_ind[x]);
            }
        } else {
            cout << q[main_q.front()].front() << endl;
            q[main_q.front()].pop();
            if (q[main_q.front()].empty()) main_q.pop();
        }
    }
    return 0;
}
