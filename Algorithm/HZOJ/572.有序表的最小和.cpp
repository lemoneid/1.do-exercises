/*************************************************************************
	> File Name: 572.有序表的最小和.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 13时50分20秒
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
#define MAX_N 400000

long long a[MAX_N + 5], b[MAX_N + 5];

struct Data {
    Data(long long val, long long i, long long j) : val(val), i(i), j(j) {}
    long long val, i, j;
    bool operator<(const Data &a) const {
        if (val - a.val) return val < a.val;
        if (i - a.i) return i < a.i;
        return j < a.j;
    }
};

set<Data> s;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", a  + i);
    for (int i = 0; i < n; ++i) scanf("%lld", b  + i);
    s.insert(Data(a[0] + b[0], 0, 0));
    for (long long i = 0; i < n; ++i) {
        long long val = s.begin()->val;
        long long x = s.begin()->i;
        long long y = s.begin()->j;
        s.erase(s.begin());
        printf("%lld\n", val);
        if (x + 1 < n) s.insert(Data(a[x + 1] + b[y], x + 1, y));
        if (y + 1 < n) s.insert(Data(a[x] + b[y + 1], x, y + 1));
    }
    return 0;
}
