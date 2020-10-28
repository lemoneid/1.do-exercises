/*************************************************************************
	> File Name: oj-531.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 13 Oct 2020 07:40:33 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int status, step;
};

int n, num2[25], check[21000000], num[25];

void init() {
    num2[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        num2[i] = 2 * num2[i - 1];
    }
}

int main() {
    init();
    cin >> n;
    int start = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1){
            start += num2[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int t;
            cin >> t;
            num[i] += num2[t];
        }
    }
    queue <node> que;
    que.push((node){start, 0});
    check[start] = 1;
    while (!que.empty()) {
        node temp = que.front();
        if (temp.status == 8) {
            cout << temp.step << endl;
            break;
        }
        que.pop();
        for (int i = 1; i <= n; ++i) {
            if ((temp.status & num2[i]) == 0) {
                int t = temp.status + num2[i];
                t &= ~num[i];
                if (check[t] == 0) {
                    check[t] = 1;
                    que.push((node){t, temp.step + 1});
                }
            }
        }
    }

    return 0;
}
