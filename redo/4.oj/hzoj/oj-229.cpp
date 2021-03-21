/*************************************************************************
	> File Name: oj-229.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 21时36分27秒
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
#define MAX_N 100000
int num[4][4];
struct Data {
    int num, step;
};
int check[MAX_N + 5];
void init() {
    for (int i = 0; i < 16; i++) {
        num[i / 4][i % 4] = 1 << i;
    }
}
int main() {
    init();
    queue<Data> que;
    char ch;
    int start = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> ch;
            if (ch == '+') start += num[i][j];
        }
    }
    check[start] = 1;
    que.push({start, 0});
    while (!que.empty()) {
        Data cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp = cur.num;
                if (temp & num[i][j]) {
                    temp -= num[i][j];
                } else {
                    temp += num[i][j];
                }
                for (int k = 0; k < 4; k++) {
                    if (temp & num[i][k]) {
                        temp -= num[i][k];
                    } else {
                        temp += num[i][k];
                    }
                    if (temp & num[k][j]) {
                        temp -= num[k][j];
                    } else {
                        temp += num[k][j];
                    }
                }
                if (temp == 0) {
                    cout << cur.step + 1 << endl;
                    return 0;
                }
                if (check[temp] == 1) continue;
                check[temp] = 1;
                que.push({temp, cur.step + 1});
            }
        }
    }
    cout << "false" << endl;
    return 0;
}
