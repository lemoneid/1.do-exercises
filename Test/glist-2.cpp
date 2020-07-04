/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月27日 星期六 18时09分32秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

typedef struct Stack {
    Node **data;
    int top, size;
} Stack;

typedef struct Queue {
    Node **data;
    int head, tail, cnt, size;
} Queue;

Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

void clear_node(Node *root) {
    if (root == NULL) return ;
    clear_node(root->lchild);
    clear_node(root->rchild);
    free(root);
    return ;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

Stack *init_stack (int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->size = n;
    s->top = -1;
    return s;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, Node *node) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = node;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear_stack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

Queue *init_queue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->cnt = q->head = q->tail = 0;
    q->size = n;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int push_queue(Queue *q, Node *val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail -= q->size;
    ++q->cnt;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    ++q->head;
    if (q->head == q->size) q->head -= q->size;
    --q->cnt;
    return 0;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

Node *build(const char *str, int *num_node) {
    Stack *s = init_stack(strlen(str));
    Node *curr = NULL, *p = NULL;
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' :
                push(s, curr);
                flag = 0;
                break;
            case ',' :
                flag = 1;
                break;
            case ')' : 
                p = top(s);
                pop(s);
                break;
            case ' ' :
                break;
            default : 
                curr = getNewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = curr;
                } else if (!empty(s) && flag == 1) {
                    top(s)->rchild = curr;
                }
                ++(*num_node);
                break;
        }
        ++str;
    }
    clear_stack(s);
    if (empty(s) && !p) p = curr;
    return p;
}

void output(Tree *tree) {
    Queue *q = init_queue(tree->n);
    if (tree->root == NULL) return ;
    push_queue (q, tree->root);
    int first = 0;
    while (!empty(q)) {
        front(q)->lchild && push_queue(q, front(q)->lchild);
        front(q)->rchild && push_queue(q, front(q)->rchild);
        first++ && cout << " ";
        cout << front(q)->data;
        pop(q);
    }
    cout << endl;
    clear_queue(q);
    return ;
}

int main() {
    Tree *tree =  (Tree *)malloc(sizeof(Tree));
    int num_node = 0;
    char str[1000];
    scanf("%[^\n]s", str);
    getchar();
    tree->root = build(str, &num_node);
    tree->n = num_node;
    output(tree);
    clear_tree(tree);
    return 0;
}
