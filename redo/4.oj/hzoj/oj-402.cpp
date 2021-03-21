/*************************************************************************
	> File Name: oj-402.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 13时24分02秒
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
#include <queue>
using namespace std;
#define MAX_N 200
int arr[MAX_N + 5];
int check[MAX_N + 5];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    queue<pair<int, int> > que;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    que.push({a, 0});
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (cur.first == b) {
            cout << cur.second<< endl;
            return 0;
        }
        int x = cur.first + arr[cur.first];
        int y = cur.first - arr[cur.first];
        if (x <= n && !check[x]) {
            check[x] = 1; 
            que.push({x, cur.second + 1});
        } 
        if (y > 0 && !check[y]) {
            check[y] = 1;
            que.push({y, cur.second + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}
