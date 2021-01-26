/*************************************************************************
	> File Name: tmp.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月22日 星期五 11时13分15秒
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
#define MAX_N 100000

struct Node {
    int id, flag, pre, next;
    long long val;
    bool operator<(const Node &obj) const {
        long long x = abs(val), y = abs(obj.val);
        if (x - y) return x < y;
        return id < obj.id;
    }
};

Node list[MAX_N + 5];
int arr[MAX_N + 5];
set<Node> s;

void del(int k) {
    if (list[k].flag == 0) return ;
    if (list[k].pre) list[list[k].pre].next = list[k].next;
    if (list[k].next) list[list[k].next].pre = list[k].pre;
    list[k].flag = 0;
    return ;
}

int main() {
    int n, m, cnt = 0;
    long long sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0, k = 1; i < n; ++k) {
        list[k].val = 0;
        list[k].flag = 1;
        list[k].id = k;
        while(i < n && arr[i] == 0) i++;
        long long val = arr[i];
        while (i < n && arr[i] * val >= 0) list[k].val += arr[i++];
        if (k - 1) list[k - 1].next = k;
        list[k].pre = k - 1;
        list[k].next = 0;
        if (list[k].val > 0) cnt += 1, sum += list[k].val;
        s.insert(list[k]);
    }

    while (cnt > m) {
        long long k = s.begin()->id;
        s.erase(s.begin());

        if (list[k].pre && list[k].next) {
            sum -= abs(list[k].val);
            cnt -= 1;
            list[k].val += list[list[k].pre].val + list[list[k].next].val;
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

