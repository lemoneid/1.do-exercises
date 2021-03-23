/*************************************************************************
	> File Name: oj-531.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 14时49分46秒
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
#include <queue>
#include <map>
using namespace std;
#define MAX_N 20
int digit[MAX_N + 5];
int arr[MAX_N + 5];
int check[21000000];
int n, start;
struct Data {
    int status, step;
};

void init() {
    digit[0] = 1;
    for (int i = 1; i < 22; i++) {
        digit[i] = digit[i - 1] * 2;
    }
}

int main() {
    init();
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        start += x == 1 ? digit[i] : 0;
    }

    for (int i = 1, op, x; i <= n; i++) {
        cin >> op;
        while (op--) {
            cin >> x;
            arr[i] += digit[x];
        }

    }
    queue<Data> que;
    que.push({start, 0});
    check[start] = 1;
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        if (cur.status  == digit[3]) {
            cout << cur.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            int x = cur.status;
            if (x & digit[i]) continue;
            x += digit[i];
            x &= ~arr[i];
            if (check[x]) continue;
            que.push({x, cur.step + 1});
            check[x] = 1;
        }
    }
    cout << -1 << endl;
    return 0;
}
