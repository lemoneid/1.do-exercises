/*************************************************************************
	> File Name: 571.关系网络1.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 11时24分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct node {
    int now, step;
};

int n, x, y, num[105][105], check[105];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> num[i][j];
        }
    }
    queue<node> que;
    que.push((node){x, 0});
    check[x] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.now == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (check[i] == 0 && num[temp.now][i] == 1) {
                check[i] = 1;
                que.push({i, temp.step + 1});
            }
        }
    }
    return 0;
}
