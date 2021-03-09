/*************************************************************************
	> File Name: 4.植物大战僵尸.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月19日 星期五 19时18分29秒
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
};

Data heap[101][MAX_N + 5];

bool gt(const Data &a, const Data &b) {
    if (a.f - b.f) return a.f > b.f;
    return a.n < b.n;
}

void push(Data *h, Data val) {
    h[++h[0].n] = val;
    int n = h[0].n;
    int ind = n;
    while (ind >> 1 && gt(h[ind], h[ind >> 1])) {
        swap(h[ind], h[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

Data top(Data *h) { return h[1]; }

void pop(Data *h) {
    swap(h[1], h[h[0].n--]);
    int ind = 1;
    while (ind << 1 <= h[0].n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (gt(h[l], h[temp])) temp = l;
        if (r <= h[0].n && gt(h[r], h[temp])) temp = r;
        if (temp == ind) break;
        swap(h[temp], h[ind]);
        ind = temp;
    }
    return ;
}

int empty(Data *h) {
    return h[0].n == 0;
}

void clear(Data *h) {
    h[0].n = 0;
}

void init_heap() {
    for (int i = 0; i <= 100; ++i) {
        clear(heap[i]);
    }
}

void solve() {
    init_heap();
    int n, f, s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &f, &s);
        push(heap[s], {i, f, s});
    }
    for (int i = 1; i <= n; i++) {
        int ind = -1, pos = 0;
        for (int j = 1; j <= 100; j++) {
            if (empty(heap[j])) continue;
            int cur_pos = (i - 1) * j + top(heap[j]).f;
            if (ind == 0 || ind && pos < cur_pos) {
                ind = j, pos = cur_pos;
            }
        }
    }
}

int main() {
    int tcase, n = 0;
    scanf("%d", &tcase);
    while (n++ < tcase) {
        printf("Case#%d:\n", n);
        solve();
    }

    return 0;
}
