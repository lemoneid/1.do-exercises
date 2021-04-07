/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 19时38分07秒
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
const int MAX_N = 5;
char matrix[MAX_N + 5][MAX_N + 5];
int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 0};
int num[MAX_N + 5][MAX_N + 5];
bool check[1 << 25];
void init() {
    for (int i = 0; i < 28; i++) {
        num[i / 5][i % 5] = 1 << i;
    }
}

struct Data {
    int status, step;
};

int solve() {
    memset(check, false, sizeof(check));
    int start = 0;
    for (int i = 0; i < 5; i++) cin >> matrix[i]; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == '1') {
                start += num[i][j]; 
            }
        }
    }
    int end = (1 << 25) - 1;
    queue<Data> que;
    que.push({start, 0});
    check[start] = true;
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        if (cur.status == end) {
            return cur.step;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int status = cur.status;
                for (int k = 0; k < 5; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;
                    if (status & num[x][y]) {
                        status -= num[x][y];
                    } else {
                        status += num[x][y];
                    }
                } 
                if (check[status]) continue;
                check[status] = true;
                que.push({status, cur.step + 1});
            }
        }
    }
    return -1;
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}
