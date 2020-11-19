/*************************************************************************
	> File Name: cd-83.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 18时09分55秒
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
#include <unordered_map>
using namespace std;
#define MAX_N 100000
int arr1[MAX_N + 5], arr2[MAX_N + 5];
int n, k;
struct Node {
    int x, y, sum;
    bool operator<(const struct Node &b) const {
        return this->sum < b.sum;
    }
};

priority_queue<Node> que;
unordered_map<int, unordered_map<int, bool>> mmap;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    que.push((Node){n - 1, n - 1, arr1[n - 1] + arr2[n - 1]});
    mmap[n - 1][n - 1] = true;
    int cnt = 0;
    while (cnt < k) {
        Node cur = que.top();
        cnt && cout << " ";
        que.pop();
        cout << cur.sum;
        cnt++;
        int x = cur.x, y = cur.y;
        if (y > 0 && !mmap[x][y - 1]) {
            que.push((Node){x, y - 1, arr1[x] + arr2[y - 1]});
            mmap[x][y - 1] = true;
        }
        if (x > 0 && !mmap[x - 1][y]) {
            que.push((Node){x - 1, y, arr1[x - 1] + arr2[y]});
            mmap[x - 1][y] = true;
        }
    }
    cout << endl;
    return 0;
}

