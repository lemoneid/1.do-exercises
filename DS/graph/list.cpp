/*************************************************************************
	> File Name: list.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月27日 星期二 20时39分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct edge {
    int e, dist, next;
};

edge edg[1005];
int n, m, head[1005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].e = b;
        edg[i].dist = c;
        edg[i].next = head[a];
        head[a] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
        for (int j = head[i]; j != -1; j = edg[j].next) {
            cout << "(" << edg[j].e << "," << edg[j].dist << ") ";
        }
        cout << endl;
    }

    return 0;
}
