/*************************************************************************
	> File Name: 3.三元组.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月19日 星期五 18时49分23秒
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


struct Node {
    char ch;
    Node *lchild, *rchild;
};

Node *arr[26];
Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->rchild = p->lchild = NULL;
    return p;
}

char str[10];

void output(Node *root) {
    if (root == NULL) return ;
    printf("%c", root->ch);
    if (!root->lchild && !root->rchild) return ;
    printf("(");
    output(root->lchild);
    if (root->rchild) {
        printf(",");
    }
    output(root->rchild);
    printf(")");
    return ;
}

int main() {
    Node *root = NULL, *p = NULL;
    while (~scanf("%s", str)) {
        if (str[0] == '^' && str[1] == '^') break;
        p = getNewNode(str[1]);
        arr[str[1] - 'A'] = p;
        if (str[0] == '^') {
            root = p;
            continue;
        }
        switch (str[2]) {
            case 'L' : arr[str[0] - 'A']->lchild = p; break;
            case 'R' : arr[str[0] - 'A']->rchild = p; break;
        }
    }
    output(root);
    return 0;
}
