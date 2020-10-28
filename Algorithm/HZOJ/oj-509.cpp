/*************************************************************************
	> File Name: oj-509.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 11时08分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 500

struct node {
    int t;
    int w;
} node[max_n + 5];

int keep[max_n + 5] = {0};

bool cmp(struct node a, struct node b) {
    return a.w > b.w;
}

int main() {
    int m, n;
    long long sum = 0, ans = 0;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> node[i].t;
    for (int i = 0; i < n; ++i) cin >> node[i].w;
    sort(node, node + n, cmp);
    for (int i = 0; i < n; ++i) {
        int ind = node[i].t;
        while (keep[ind]) ind--;
        if (ind < 1) {
            sum += node[i].w;
            continue;
        }
        keep[ind] = 1; 
    } 
    ans = m - sum;
    cout << ans << endl;
    return 0;
}
