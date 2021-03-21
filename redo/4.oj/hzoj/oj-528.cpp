/*************************************************************************
	> File Name: oj-528.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 13时37分58秒
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
#define MAX_N 100
int arr[MAX_N + 5][MAX_N + 5];
int check[MAX_N + 5];
int n;
struct Data {
    int now, step;
};

int main() {
    int s, e;
    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    queue<Data> que; 
    que.push({s, 0});
    check[s] = 1;
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        if (cur.now == e) {
            cout << cur.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (check[i] || arr[cur.now][i] == 0) continue;
            que.push({i, cur.step + 1});
            check[i] = 1;
        }
    }
    cout << 0 << endl;
    return 0;
}
