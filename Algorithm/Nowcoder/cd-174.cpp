/*************************************************************************
	> File Name: cd-174.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 14时02分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define MAX_N 10000

int pre[MAX_N + 5], in[MAX_N + 5], ans[MAX_N + 5];
unordered_map<int, int> mmap;
int setPos(int *pre, int pl, int pr, int *in, int il, int ir, int *ans, int s) {
    if (pl > pr) return s;
    ans[s--] = pre[pl];
    int id = mmap[pre[pl]];
    s = setPos(pre, pr - (ir - (id + 1)), pr, in, id + 1, ir, ans, s);
    return setPos(pre, pl + 1, pl + id  - il, in, il, id - 1, ans, s);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", pre + i);
    for (int i = 0; i < n; ++i) scanf("%d", in + i), mmap[in[i]] = i;
    setPos(pre, 0, n - 1, in, 0, n - 1, ans, n - 1);
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", ans[i]);
    } 
    printf("\n");
    return 0;
}
