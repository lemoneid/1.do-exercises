/*************************************************************************
	> File Name: cd-64.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 13时32分18秒
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
#include <unordered_map>
using namespace std;

unordered_map<int, int> mapKV;
unordered_map<int, int> mapValue;
deque<int> que;
int n, m;

void del(int key) {
    if (mapKV[key] < 0 && mapValue[mapKV[key]] < 0) return ;
    stack<int> stk;
    while (que.front() != key && que.size()) {
        stk.push(que.front());
        que.pop_front();
    }
    if (que.size()) que.pop_front();
    while (!stk.empty()) {
        que.push_front(stk.top());
        stk.pop();
    }
    return ;
}

void set(int key, int val) {
    int res = mapKV[key];
    del(key);
    que.push_back(key);
    mapKV[key] = val;
    mapValue[val] = key;
    while (que.size() > m) {
        mapValue[mapKV[que.front()]] = -1;
        mapKV[que.front()] = -1; 
        que.pop_front();
    }
}

int get(int key) {
    int ans = mapKV[key];
    if (ans < 0) return -1;
    del(key);
    que.push_back(key);
    while (que.size() > m) {
        mapValue[mapKV[que.front()]] = -1;
        mapKV[que.front()] = -1; 
        que.pop_front();
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0, op, x, y; i < n; ++i) {
        cin >> op >> x;
        switch(op) {
            case 1 : 
                cin >> y;
                set(x, y);
                break;
            case 2 : 
                cout << get(x) << endl;
                break;
        }
    }

    return 0;
}
