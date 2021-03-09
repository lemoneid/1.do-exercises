/*************************************************************************
	> File Name: oj-268-2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 14时22分32秒
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
    int val;
    Node *next;
};

class Queue {
public :
    Queue() {
        head = new Node;
        tail = new Node;
        head->next = tail;
    }
    
    int pop(map<int, int> &ind) {
        Node *p = head->next;
        delete head;
        head = p;
        if (mmap[ind[head->val]] == head) mmap[ind[head->val]] = NULL;
        return head->val;
    }
    void push(int k, map<int, int> &ind) {
        if (!mmap[ind[k]]) {
            Node *p = new Node;
            tail->val = k;
            tail->next = p;
            mmap[ind[k]] = tail;
            tail = tail->next;
        } else {
            Node *p = mmap[ind[k]];
            p->next = new Node{k, p->next};
            mmap[ind[k]] = p->next;
        }
    }
    ~Queue() {
        Node *p = head;
        while (head) {
            p = head->next;
            delete head;
            head = p;
        }
    }
    Node *head, *tail;
    map<int, Node *> mmap;
};

map<int, int> ind;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0, m; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0, a; j < m; j++) {
            scanf("%d", &a);
            ind[a] = i;
        }
    }
    string op;
    Queue q;
    while (cin >> op) {
        if (op[0] == 'S') break;
        if (op[0] == 'E') {
            int x; 
            scanf("%d", &x);
            q.push(x, ind);
        } else {
            printf("%d\n", q.pop(ind));
        }
    }
    return 0;
}
