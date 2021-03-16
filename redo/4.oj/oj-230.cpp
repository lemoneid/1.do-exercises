/*************************************************************************
	> File Name: oj-230.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 22时01分48秒
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
#define MAX_N 100000000
int num[5][5];
int check[MAX_N + 5];
int dir[5][2] = {0 , 1, 1, 0, 0, -1, -1, 0, 0, 0};
struct Data {
    int num, step;
};
void init() {
    for (int i = 0; i < 25; i++) {
        num[i / 5][i % 5] = 1 << i;
    }
    return ;
}

int solve() {
    int start = 0;
    memset(check, 0, sizeof(check));
    char ch;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> ch;
            if (ch == '0') {
                start += num[i][j];
            }
        }
    }
    queue<Data> que;
    check[start] = 1;
    que.push({start, 0});
    int ans = -1;
    while (!que.empty()) {
        Data cur = que.front();
        cout << cur.num << endl;
        que.pop();
        if (cur.num == 0) {
            ans = cur.step;
            break;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int temp = cur.num;
                for (int k = 0; k < 5; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || y < 0 || x > 4 || y > 4) continue;
                    if (temp & num[x][y]) {
                        temp -= num[x][y];
                    } else {
                        temp -= num[x][y];
                    }
                }
                if (check[temp]) continue;
                check[temp] = 1;
                que.push({temp, cur.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main() {
    init();
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}
