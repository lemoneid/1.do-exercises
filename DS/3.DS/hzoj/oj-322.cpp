/*************************************************************************
	> File Name: oj-322.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月29日 星期五 19时13分11秒
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
#define MAX_N 1000000

struct UnionSet {
    int father[MAX_N << 1 + 5];
    void init(int n) {
        while (n--) father[n + 1] = n + 1;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        // father[get(a)] = father[get(b)];
        father[get(a)] = get(b);
    }
};

struct Data {
    int e, i, j;
} arr[MAX_N + 5];

UnionSet u;

void solve() {
    map<int, int> ind;
    int cnt =  0;
    int n;
    cin >> n;
    u.init(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].i >> arr[i].j >> arr[i].e;
        if (ind.find(arr[i].i) == ind.end()) ind[arr[i].i] = (++cnt);
        if (ind.find(arr[i].j) == ind.end()) ind[arr[i].i] = (++cnt);
        arr[i].i = ind[arr[i].i];
        arr[i].j = ind[arr[i].j];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i].e == 0) continue;
        u.merge(arr[i].i, arr[i].j);
    }
    int flag = 1;
    for (int i = 0; i < n && flag; ++i) {
        if (arr[i].e == 1) continue;
        flag = (u.get(arr[i].i) != u.get(arr[i].j));
    }
    cout << (flag ? "YES" : "NO") << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
