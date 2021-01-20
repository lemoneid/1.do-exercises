#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

typedef struct ListNode {
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
    ~ListNode() {
        next = nullptr;
    }
} ListNode;

typedef struct List {
    ListNode dummy;
    int length;
    List() : dummy(0) , length(0) {}
    ~List() {
        length = 0;
        dummy.next = nullptr;
    }
} List;

ListNode *getNewNode(int val) {
    ListNode *p = new ListNode(val);
    return p;
}

List *getNewList() {
    List *p = new List;
    return p;
}

bool insert(List *l, int idx, int val) {
    if (!l) return false;
    if (idx < 0 || idx > l->length) return false;
    ListNode *p = &(l->dummy), *q = nullptr;
    while (idx--) p = p->next;
    q = p->next;
    p->next = getNewNode(val);
    p->next->next = q;
    l->length++;
    return true;
}

bool erase(List *l, int idx) {
    if (!l) return false;
    if (idx < 0 || idx >= l->length) return false;
    ListNode *p = &(l->dummy), *q = nullptr;
    while (idx--) p = p->next;
    q = p->next;
    p->next = p->next->next;
    delete q;
    l->length--;
    return true;
}

void reverse(List *l) {
    if(!l || l->length < 2) return ; 
    ListNode *head = &(l->dummy), *p = head->next, *q = nullptr;
    while (p && p->next) {
        q = head->next;
        head->next = p->next;
        p->next = p->next->next;
        head->next->next = q;

    }
    return ;
}

void output(List *l) {
    printf("List(%d) = [", l->length);
    ListNode *head = &(l->dummy);
    while (head->next) {
        head != &(l->dummy) && printf(", ");
        printf("%d", head->next->data);
        head = head->next;
    }
    printf("]\n");
    return ;
}

void clear(List *l) {
    cout << "the list is clearing..." << endl;
    if (!l) return ;
    ListNode *p = (l->dummy).next, *q = nullptr;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    delete l;
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    List *l = getNewList();
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 7;
        ind = rand() % (l->length + 3);
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("reverse the list\n");
                reverse(l);
            } break;
            case 3: {
                printf("erase item at %d from List = %d\n", ind, erase(l, ind));
            } break;
            default : {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
        }
        output(l);
        printf("\n");
    }
    clear(l);
    output(l);
    return 0;
}
