/*************************************************************************
	> File Name: oj-229.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 17时47分17秒
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

struct Node {
    int status, step;
};

int sta[4][4] = {
    1, 2, 4, 8, 
    16, 32, 64, 128,
    256, 512, 1024, 2048,
    4096, 8192, 16384, 32768
};

int check[100000];

int main() {
    int start = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char t;
            cin >> t;
            if (t == '+') {
                start += sta[i][j];
            }
        }
    }
    queue<Node> que;
    que.push((Node){start, 0});
    check[start] = 1;
    while (!que.empty()) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                Node temp = que.front();
                if (temp.status & sta[i][j]) {
                    temp.status -= sta[i][j];
                } else {
                    temp.status += sta[i][j];
                }
                for (int k = 0; k < 4; ++k) {
                    if (temp.status & sta[i][k]) {
                        temp.status -= sta[i][k];
                    } else {
                        temp.status += sta[i][k];
                    }
                    if (temp.status & sta[k][j]) {
                        temp.status -= sta[k][j];
                    } else {
                        temp.status += sta[k][j];
                    }
                }
                temp.step++;
                if (temp.status == 0) {
                    cout << temp.step << endl;
                    return 0;
                }
                if (check[temp.status] == 0) {
                    check[temp.status] = 1;
                    que.push(temp);
                }
            }
        }
        que.pop();
    }
    return 0;
}
