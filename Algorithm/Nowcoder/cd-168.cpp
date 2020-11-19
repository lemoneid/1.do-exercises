/*************************************************************************
	> File Name: cd-168.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月16日 星期一 11时00分30秒
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
    int val, lchild, rchild;
};
vector<Node> v;

int getMaxDepth(int root) {
    if (root == 0) return 0;
    return max(getMaxDepth(v[root].lchild), getMaxDepth(v[root].rchild)) + 1;
}

void getLevelCnt(int root, int level, int *arr) {
    if (root == 0) return ;
    arr[level] += 1;
    getLevelCnt(v[root].lchild, level + 1, arr);
    getLevelCnt(v[root].rchild, level + 1, arr);
    return ;
}

void getAnsArray(int root, int level,int *cnt, int **arr) {
    if (root == 0) return ;
    arr[level][cnt[level]++] = v[root].val;
    getAnsArray(v[root].lchild, level + 1, cnt, arr);
    getAnsArray(v[root].rchild, level + 1, cnt, arr);
    return ;
}

void output(int *cnt, int **ans, int depth) {
    for (int i = 1; i <= depth; ++i) {
        printf("Level %d :", i);
        for (int j = 0; j < cnt[i]; ++j) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= depth; ++i) {
        printf("Level %d ", i);
        if (i & 1){
            printf("from left to right:");
            for (int j = 0; j < cnt[i]; ++j) {
                printf(" %d", ans[i][j]);
            }
        } 
        else {
            printf("from right to left:");
            for (int j = cnt[i] - 1; j >= 0; --j) {
                printf(" %d", ans[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    v.resize(n + 1);
    for (int i = 0, x, l, r; i < n; ++i) {
        scanf("%d%d%d", &x, &l, &r);
        v[x].val = x;
        v[x].lchild = l;
        v[x].rchild = r;
    }
    int depth = getMaxDepth(root);
    int *cnt = (int *)calloc(sizeof(int), (depth + 2));
    int **ans = (int **)malloc(sizeof(int *) * (depth + 2));
    getLevelCnt(root, 1, cnt);
    for (int i = 1; i <= depth; ++i) {
        ans[i] = (int *)malloc(sizeof(int) * (cnt[i] + 1));
        cnt[i] = 0;
    }
    getAnsArray(root, 1, cnt, ans);
    output(cnt, ans, depth);
    free(cnt);
    free(ans);
    return 0;
}
