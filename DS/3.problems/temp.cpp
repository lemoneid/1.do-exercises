/*************************************************************************
	> File Name: temp.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月19日 星期五 20时19分43秒
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

#define MAX_N 50000

struct Data {
    int n, f, s;
    bool operator<(const Data &obj) const {
        if (this->f - obj.f) return this->f > obj.f;
        return this->n < obj.n;
    }
} arr[MAX_N + 5];

bool check[MAX_N + 5];

set<Data> heap;

void solve() {
    memset(check, sizeof(check), 0);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
        arr[i].n = i;
        heap.insert(arr[i]);
    }
    int flag = 0;
    while (!heap.empty()) {
        auto cur = heap.begin();
        cout << cur->n;
        if (flag) cout << " ";
        flag = 1;
        heap.erase(heap.begin());
    }
    cout << endl;
}

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        solve();
    }

    return 0;
}
