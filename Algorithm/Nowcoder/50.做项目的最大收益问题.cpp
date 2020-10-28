/*************************************************************************
	> File Name: 50.做项目的最大收益问题.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 18时27分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 100000

struct node {
    int cost, profits;
};

node data[MAX_N + 5];
int check[MAX_N + 5];
int n, w, k;

int cmp(node a, node b) {
    if (a.profits != b.profits) {
        return a.profits > b.profits;
    }
    return a.cost < b.cost;
}

int main() {
    cin >> n >> w >> k;
    for (int i = 0; i < n; ++i) {
        cin >> data[i].cost;
    }
    for (int i = 0; i < n; ++i) {
        cin >> data[i].profits;
    }
    sort(data, data + n, cmp);
    while (k--) {
        for (int i = 0; i < n; ++i) {
            if (!check[i] && data[i].cost <= w) {
                w += data[i].profits;
                check[i] = 1;
                break;
            }
        }
    }
    cout << w << endl;
    return 0;
}
