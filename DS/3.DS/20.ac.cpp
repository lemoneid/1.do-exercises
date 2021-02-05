/*************************************************************************
	> File Name: 20.ac.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月27日 星期三 19时44分10秒
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
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *fail, *next[BASE];
} Node;

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->size = n;
    q->head = q->tail = 0;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
}

void clear_queue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, char *s) {
    if (!root) return 0;
    Node *p = root;
    int cnt = 0;
    for (int i = 0; s[i]; ++i) {
        int idx = s[i] - BEGIN_LETTER;
        if (!p->next[idx]) p->next[idx] = getNewNode(), cnt += 1;
        p = p->next[idx];
    }
    p->flag = 1;
    return cnt;
}

void build_ac(Node *root, int n) {
    Queue *q = init_queue(n + 10);
    root->fail = nullptr;
    push(q, root);
    while (!empty(q)) {
        Node *cur = front(q);
        pop(q);
        for (int i = 0; i < BASE; ++i) {
            if (!cur->next[i]) continue;
            Node *ptr = cur->fail;
            while (ptr && !ptr->next[i]) ptr = ptr->fail;
            cur->next[i] = !ptr ? root :  ptr->next[i];
            push(q, cur->next[i]);
        }
    }
    return ;
}

int match(Node *root, const char *s) {
    Node *p = root;
    int cnt = 0;
    for (int i = 0; s[i]; ++i) {
        int ind = s[i] - BEGIN_LETTER;
        while (p && !p->next[ind]) p = p->fail;
        if (!p) p = root;
        else p = p->next[ind]; 
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}

void clear(Node *root) {
    if (!root) return;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    Node *root = getNewNode();
    char str[10000];
    int n, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        cnt += insert(root, str);
    }
    //build ac
    build_ac(root, cnt);
    cin >> str;
    //match ac
    printf("match %d int ac", match(root, str));
    return 0;
}
