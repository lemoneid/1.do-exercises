/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月25日 星期四 17时35分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Queue {
    Node **data;
    int size, cnt;
    int head, tail;
} Queue;

Node *get_node(char data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->data = data;
    return p;
}

Queue *init_queue(int n) {
    Queue *q = (Queue *)malloc(sizeof (Queue));
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->size = n;
    q->head = q->tail = q->cnt = 0;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int push(Queue *q, Node *node) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[q->tail++] = node;
    if (q->tail == q->size) q->tail -= q->size;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head += 1;
    if (q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;
}

Node *create_tree(const char *str, int *num_node) {
    Node *root = NULL, *current = NULL;
    stack<Node *> s;
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' :
                s.push(current);
                flag = 1;
                break;
            case ',' :
                flag = 0;
                break;
            case ')' :
                s.pop();
                break;
            case ' ' : break;
            default :
                current = get_node(str[0]);
                if (root == NULL) {
                    root = current;
                } else {
                    flag == 1 ? s.top()->lchild = current : s.top()->rchild = current;
                }
                *num_node += 1;
                break;
        }
        str += 1;
    }
    while (!s.empty()) s.pop();
    return root;
}

void order(Node *node, int first, Queue *q) {
    if (first) push(q, node);
    if (empty(q)) return ;
    node->lchild  && push(q, node->lchild);
    node->rchild && push(q, node->rchild);

    !first && cout << " ";
    cout << front(q)->data;
    pop(q);
    order(front(q), 0, q);
    return ;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
}

char str[1000] = {0};

int main() {
    int num_node = 0;
    scanf("%[^\n]s", str);
    getchar();
    Node *root = create_tree(str, &num_node);
    if (root == NULL) return 0;
    Queue *q = init_queue(num_node);
    order(root, 1, q);
    clear_queue(q);
    clear(root);
    return 0;
}

