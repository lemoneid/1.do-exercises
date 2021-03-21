/*************************************************************************
	> File Name: oj-283.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 08时28分49秒
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
#define MAX_N 10000
struct Node {
    int flag;
    int next[10];
} tree[MAX_N * 10 + 5];

const int root = 1;
int cnt = 1;
inline int getNode() { return ++cnt; };
char str[100];

bool insert(char *str) {
    int p = root;
    bool ans = true;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - '0';
        if (!tree[p].next[ind]) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
        if (tree[p].flag) ans = false;
    }
    for (int i = 0; i < 10; i++) {
        if (tree[p].next[i]) ans = false;
    }
    tree[p].flag = 1;
    return ans;
}


int main() {
    int n;
    scanf("%d", &n);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (!ans) continue;
        ans = insert(str);
    }
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
