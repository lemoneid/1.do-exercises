/*************************************************************************
	> File Name: 573.桐桐的新闻系统.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 14时48分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct Data {
    Data(int t, int id, int p) : t(t), p(p), id(id) {}
    int t, id, p;
    bool operator<(const Data &a) const {
        if (t - a.t) return t < a.t;
        return id < a.id;
    }
};

set<Data> s;

int main() {
    string op;
    int id, p, k;
    while (cin >> op) {
        if (op == "#") break;
        cin >> id >> p;
        s.insert(Data(p, id, p));
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int t = s.begin()->t;
        int id = s.begin()->id;
        int p = s.begin()->p;
        s.erase(s.begin());
        printf("%d\n", id);
        s.insert(Data(t + p, id, p));
    }

    return 0;
}
