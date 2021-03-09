/************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月25日 星期四 17时35分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;


Node *get_node(char);
void pre_order(Node *);
void in_order(Node *);
void post_order(Node *);
void clear(Node *);
Node *create_tree(string str) {
    Node *root = NULL, *current = NULL;
    stack<Node*> s;
    int flag = 0, i = 0;
    char c = str[0];
    while (c != '\0' && c != '\n') {
        switch (c) {
            case '(' : {
                s.push(current);
                flag = 1;
            } break;
            case ',' : {
                flag = 0;
            } break;
            case ')' : {
                s.pop();
            } break;
            case ' ' : break;
            default : {
                current = get_node(c);
                cout << current->data << endl;
                if (root == NULL) {
                    root = current;
                } else {
                    flag == 1 ? s.top()->lchild = current : s.top()->rchild = current;
                }
            } break;
        }
        c = str[++i];
    }
    while (!s.empty()) s.pop();
    return root;
}

int main() {
    string str = "A (B (C, D), E ( , F))";
    Node *root = create_tree(str);
    cout << "pre_order : ";
    pre_order(root);
    cout << endl;
    cout << "in_order : ";
    in_order(root);
    cout << endl;
    cout << "post_order : ";
    post_order(root);
    cout << endl;
    clear(root);
}

Node *get_node(char data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->data = data;
    return p;
}

void pre_order(Node *root) {
    if (root == NULL) return ;
    cout << root->data;
    pre_order(root->lchild);
    pre_order(root->rchild);
}

void in_order(Node *root) {
    if (root == NULL) return ;
    in_order(root->lchild);
    cout << root->data;
    in_order(root->rchild);
}

void post_order(Node *root) {
    if (root == NULL) return ;
    post_order(root->lchild);
    post_order(root->rchild);
    cout << root->data;
}

void clear(Node *node) {
    if (node == NULL) return ;
    if (node->lchild == NULL && node->rchild == NULL) {
        free(node);
    }
    clear(node->lchild);
    clear(node->rchild);
    return ;
}
