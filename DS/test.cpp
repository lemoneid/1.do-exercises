/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月09日 星期二 16时12分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *getNewNOde(int);
List *getLinkList();
void clear_node(ListNode *);
void clear_list(List *);
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *);

int main() {
    srand(time(0));
    #define max_op 20
    List *l = getLinkList();
    int ind, op, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase a iterm at %d from List = %d\n", ind, erase(l, ind));
            } break;
            case 3: {
                printf("print the List !\n");
               // reveser(l);
            } break;
        }
        output(l);
    } 
    clear_list(l);
    #undef max_op
    return 0;
}

ListNode *getNewNOde(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->next = NULL;
    p->prev = NULL;
    p->data = val;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->head.prev = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = getNewNOde(val);
    while (ind--) p = p->next;
    node->next = p->next;
    node->prev = p;
    p->next = node;
    node->next->prev = node;
    l->length += 1;
    return 1;
}
int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    l->length -= 1;
    free(q);
    return 1;
}

void output(List *l) {
    cout << "List(" << l->length << ") = [";
    for(ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    cout <<"NULL]" << endl;
    return ;
}

void clear_node(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_list(List *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}
