/*************************************************************************
	> File Name: oj-282.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月17日 星期三 10时36分45秒
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
using namespace std;
#define MAX_N 100000
#define BASE 31
struct Node {
    Node *next[2];
} tree[BASE * MAX_N + 5];
int cnt = 0;
Node *getNewNode() {
    return &tree[cnt++];
}

void insert(Node *root, int x) {
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i)); //归一化
        if (!root->next[ind]) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
    return ;
}

int query(Node *root, int x) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int ind = !(x & (1 << i));
        if (root->next[ind]) {
            ans |= (1 << i);
            root = root->next[ind];
        } else {
            root = root->next[!ind];
        }
    }
    return ans;
}

int n;
int val[MAX_N + 5];

int main() {
    cin >> n;
    int ans = 0, a;
    Node *root = getNewNode();
    cin >> a, n--;
    insert(root, a);
    while (n--) {
        cin >> a;
        ans = max(query(root, a), ans);
        insert(root, a);
    }
    cout << ans << endl;
    return 0;
}
