/*************************************************************************
	> File Name: oj-281.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 21时47分50秒
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
#define BEGIN 'a'
#define MAX_N 26

char s[1000000];
struct Node{
    struct Node *next[MAX_N];
    int flag;
};

Node *getNewNode() {
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

void insert(Node *root, char *str) {
    if (!root) return ;
    for (int i = 0; str[i]; i++)  {
        int ind = str[i] - BEGIN;
        if (!root->next[ind]) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
    root->flag += 1;
    return ;
}

int query(Node *root, char *str) {
    if (!root || !str) return 0;
    int cnt = 0;
    for (int i = 0; str[i] && root; i++) {
        int ind = str[i] - BEGIN;
        if (!root->next[ind]) break;
        root = root->next[ind];
        cnt += root->flag;
    }
    return cnt;
}


int main() {
    int n, m;
    cin >> n >> m; 
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(root, s);
    } 
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        printf("%d\n", query(root, s));
    } 
    return 0;
}
