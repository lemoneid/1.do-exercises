/*************************************************************************
	> File Name: list.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 21时34分32秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

typedef struct Node {
    int data;
    struct Node *next;
} Node; 

typedef struct LinkList {
    Node head;
    int n;
} LinkList;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_list() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->n = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->n) return 0;
    Node *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->n += 1;
    return 1;
}

int earse(LinkList *l, int ind) {
    if (l ==  NULL) return 0;
    if (ind < 0 || ind >= l->n) return 0;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->n -= 1;
    return 1;
}

int reverse(LinkList *l) {
    if (l == NULL) return 0;
    Node *p = (l->head).next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return 1;
}

void clear_node(Node *p) {
    if (p == NULL) return;
    free(p);
    return ;
}

void clear_list(LinkList *l) {
    if (l == NULL) return ;
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}

void output(LinkList *l) {
    Node *p = (l->head).next;
    printf("list(%d) : [", l->n);
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    LinkList *l = init_list();
    int op, ind, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (l->n + 1);
        val = rand() % 100;
        switch (op) {
            case 0:
                printf("earse a item at %d from list = %d\n", ind, earse(l, ind));
                break;
            case 1 : 
                printf("reverse list = %d\n", reverse(l));
                break;
            case 2 :
            case 3 :
                printf("insert %d at %d to list  = %d\n", val, ind, insert(l, ind, val));
                break;
        }
        output(l);
    }
    clear_list(l);
    #undef max_op
    return 0;
}
