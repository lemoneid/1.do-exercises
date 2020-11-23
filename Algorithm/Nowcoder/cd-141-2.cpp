/*************************************************************************
	> File Name: cd-141-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 18时44分21秒
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
const int MAX_N = 100000;
struct Node {
    struct Node *next[2];
};

int arr[MAX_N + 5], n;

inline Node *getNode() {
    Node *p = (Node*)calloc(sizeof(Node), 1);
    return p;
}

inline void add(Node *root, int num) {
    Node *cur = root;
    for (int move = 31; move > -1; move--) {
        //取num的第i位判是否为1
        int path = ((num >> move) & 1);
        cur->next[path] = cur->next[path] == NULL ? getNode() : cur->next[path];
        cur = cur->next[path];
    }
}

inline int maxXor(Node *root, int eorj) {
    Node *cur = root; 
    int res = 0;
    for (int move = 31; move > -1; move--) {
        int path = ((eorj >> move) & 1);
        int best = (move == 31 ? path : (path ^ 1));
        best = cur->next[best] != NULL ? best : (best ^ 1);
        res |= (path ^ best) << move;
        cur = cur->next[best];
    }
    return res;
}

int maxXorSubarray(int *arr, int n) {
    if (arr == NULL || n == 0) return 0;
    int res = 0x80000000, eor = 0;
    Node *root = getNode();
    add(root, 0);
    for (int j = 0; j < n; ++j) {
        eor ^= arr[j];
        res = max(res, maxXor(root, eor));
        add(root, eor);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    int res = maxXorSubarray(arr, n);
    printf("%d\n", res);
    return 0;
}
