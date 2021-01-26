/*************************************************************************
	> File Name: oj-289.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月21日 星期四 18时14分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define MAX_N 100000

struct Node {
    long long val, id, flag;
    long long pre, next;
    bool operator<(const Node &a) const {
        if (abs(val) - abs(a.val)) return abs(val) < abs(a.val);
        return id < a.id;
    }
};

long long arr[MAX_N + 5];
Node list[MAX_N + 5];
set<Node> s;

void del(long long k) {
    if (list[k].flag == 0) return;
    if (list[k].pre) list[list[k].pre].next = list[k].next;
    if (list[k].next) list[list[k].next].pre = list[k].pre;
    list[k].flag = 0;
    return ;
}

int main() {
    long long n, m, cnt = 0, sum = 0;
    cin >> n >> m;
    for (long long i = 0; i < n; ++i) cin >> arr[i];
    for (long long i = 0, k = 1; i < n; k++) {
        list[k].val = 0;
        list[k].id = k;
        list[k].flag = 1;
        while (i < n && arr[i] == 0) i++;
        long long val = arr[i];
        while (i < n && arr[i] * val >= 0) {
            list[k].val += arr[i++];
        }
        if (k != 1) list[k - 1].next = k;
        list[k].pre = k - 1;
        list[k].next = 0;
        if (list[k].val > 0) cnt += 1, sum += list[k].val;
        s.insert(list[k]);
    }
    
    while (cnt > m) {
        long long k = s.begin()->id;
        s.erase(s.begin());
        if (list[k].flag == 0) continue;
        if (list[k].pre && list[k].next) {
            sum -= abs(list[k].val);
            cnt -= 1;
            list[k].val += list[list[k].pre].val;
            list[k].val += list[list[k].next].val;
            del(list[k].pre);
            del(list[k].next);
            s.insert(list[k]);
        } else {
            if (list[k].val > 0) sum -= list[k].val, cnt -= 1;
            del(k);
        }
    }
    cout << sum << endl;
    return 0;
}
