/*************************************************************************
	> File Name: 6.table_to_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 09时15分00秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>

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

Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree  = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Stack *init_stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)calloc(n, sizeof(Node *));
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int push(Stack *s, Node *val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void clear_stack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
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

Node *build(const char *str, int *node_num) {
    Stack *s = init_stack(strlen(str));
    Node *tmp = NULL, *p = NULL;
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(':
                push(s, tmp);
                flag = 0;
                break;
            case ')':
                p = top(s);
                pop(s);
                break;
            case ',':
                flag = 1;
                break;
            case ' ':
                break;
            default :
                tmp = getNewNode(str[0]);
                if (!empty(s) && !flag) {
                    top(s)->lchild = tmp;
                } else if (!empty(s) && flag) {
                    top(s)->rchild = tmp;
                }
                ++(*node_num);
                break;
        }
        ++str;
    }
    clear_stack(s);
    if (tmp && !p) p = tmp;
    return p;
}

void in_order_node(Node *root) {
    if (root == NULL) return ;
    in_order_node(root->lchild);
    printf("%c ", root->data);
    in_order_node(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    if (tree == NULL) return; 
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}

int main() {
    char str[1000] = {0};
    int node_num;
    scanf("%[^\n]s", str);
    getchar();
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    in_order(tree);
    clear_tree(tree);
    return 0;
}
