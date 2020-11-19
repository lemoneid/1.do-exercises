#include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node * relocate(list_node * head)
{
    //////在下面完成代码
    if (head == NULL || head->next == NULL) return nullptr;
    list_node *p = head, *q = head->next, *pp = NULL, *qq = NULL;
    while (q->next && q->next->next) p = p->next, q = q->next->next;
    q = p->next;
    p->next = NULL;
    p = head;
    while (p) {
        pp = p->next;
        qq = q->next;
        p->next = q;
        q->next = pp;
        p = pp;
        q = qq;
    }
    /*
    while (p->next) {
        qq = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        q = qq;
    }
    p->next = q;
    */
    return head;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}
