/*************************************************************************
	> File Name: list.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月07日 星期三 13时43分06秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;
    return p;
}

Node *init(int n) {
    int tmp;
    Node *pre, *head, *cur;
    scanf("%d", &tmp);
    head = getNewNode(tmp);
    pre = cur = head;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &tmp);
        cur = getNewNode(tmp);
        pre->next = cur;
        pre = cur;
    }
    cur->next = NULL;
    return head;
}

void output(Node *head) {
    Node *cur = head;
    while (cur) {
        cur != head && printf(" ");
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");
    return ;
}
Node *reverse_part(Node *left, Node *start, Node *end,  Node *right) {
    Node *pre = start, *p = start->next, *q;
    while (p != right) {
        q = p->next;
        p->next = pre;
        pre = p;
        p = q;
    }
    if (left) left->next = end;
    start->next = right;
}

Node *reverse(Node *head) {
    Node ret, *p = head, *q;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

Node *calc(Node *head1, Node *head2) {
    int val = 0;
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node *pre = NULL, *cur;
    while (head1 || head2) {
        val = val / 10;
        val += head1 ? head1->val : 0;
        val += head2 ? head2->val : 0;
        cur = getNewNode(val % 10);
        cur->next = pre;
        pre = cur;
        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }
    if (val / 10) {
        cur = getNewNode(1);
        cur->next = pre;
    }
    return cur;
}

Node *merge(Node *head1, Node *head2) {
    Node *head = NULL, *pre = NULL, *cur = NULL;
    while (head1 && head2) {
        if (head1->val == head2->val) {
            cur = head1;
            head1 = head1->next;
        } else if (head1->val < head2->val) {
            cur = head1;
            head1 = head1->next;
        } else {
            cur = head2;
            head2 = head2->next;
        }
        if (!head) head = cur;
        if (!pre) {
            pre = cur;
        } else {
            pre->next = cur;
            pre = cur;
        }
    }
    pre->next = head1 ? head1 : head2;
    return head;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Node *head = init(n);
    Node *h1, *p1, *h2, *p2, *h3, *p3;
    Node *next = NULL;
    h1 = p1 = h2 = p2 = h3 = p3 = NULL;
    while (head) {
        next = head->next;
        if (head->val < m) {
            if (!h1) {
                h1 = p1 = head;
            } else {
                p1->next = head;
                p1 = head;
            }
            p1->next = NULL;
        } else if (head->val == m) {
            if (!h2) {
                h2 = p2 = head;
            } else {
                p2->next = head;
                p2 = head;
            }
            p2->next = NULL;
        } else {
            if (!h3) {
                h3 = p3 = head;
            } else {
                p3->next = head;
                p3 = head;
            }
            p3->next = NULL;
        }
        head = next;
    }
    if (h1) {
        head = h1;
        if (h2) {
            p1->next = h2;
            p2->next = h3;
        } else {
            p1->next = h3;
        }
    } else {
        if (h2) {
            head = h2;
            p2->next = h3;
        } else {
            head = h3;
        }
    }
    output(head);
    return 0;
}
