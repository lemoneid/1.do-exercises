/*************************************************************************
	> File Name: oj-402.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Mon 31 Aug 2020 11:26:35 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int num, step;
};

int n, a, b;
int mmap[205];
int flag[205];

int main() {
    cin >> n >> a >> b;
    queue <node> que;
    for (int i = 1; i <= n; ++i) {
        cin >> mmap[i];
    }
    que.push({a, 0});
    flag[a] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.num == b) {
            cout << temp.step << endl;
            return 0;
        }
        int x = temp.num + mmap[temp.num];
        if (x <= n && !flag[x])  {
            que.push({x, temp.step + 1});
            flag[x] = 1;
        }
        int y = temp.num - mmap[temp.num];
        if (y > 0 && !flag[y]) {
            que.push({y, temp.step + 1}); 
            flag[y] = 1;
        }
    }
    cout << -1 << endl;

    return 0;
}
