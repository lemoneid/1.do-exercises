/*************************************************************************
	> File Name: oj-572.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 22时42分02秒
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
const int MAX_N = 400000;
long long a[MAX_N + 5], b[MAX_N + 5], n;

struct Data {
    long long val;
    int i, j;
    bool operator<(const Data &obj) const {
        if (this->val - obj.val) return this->val < obj.val;
        if (this->i < obj.i) return this->i < obj.i;
        return this->j < obj.j;
    }
};

set<Data> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    s.insert(Data{a[0] + b[0], 0, 0});
    for (int i = 0; i < n; ++i) {
        long long val = s.begin()->val;
        int x = s.begin()->i;
        int y = s.begin()->j;
        s.erase(s.begin());
        cout << val << endl;
        if (x + 1 < n) s.insert(Data{a[x + 1] + b[y], x + 1, y});
        if (y + 1 < n) s.insert(Data{a[x] + b[y + 1], x, y + 1});
    }

    return 0;
}
