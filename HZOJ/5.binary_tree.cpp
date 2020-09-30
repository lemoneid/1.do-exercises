/*************************************************************************
	> File Name: 5.binary_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 22时30分54秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct Node {
    int val;
    struct Node *next[2];
} Node;

typedef struct Tree{
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next[0] = p->next[1] = NULL;
    return p;
}

Tree *init_tree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insert_node(Node *root, int val) {
    if (root == NULL) {
        return getNewNode(val);
    }
    if (root->val == val) return root;
    if (root->val < val) root->next[0] = insert_node(root->next[0], val);
    else root->next[1] = insert_node(root->next[1], val);
    return root;
}

int insert(Tree *tree, int val) {
    insert_node(tree->root, val);
    return 1;
}

void in_order_node(Node *root) {
    if (root == NULL) return;
    printf("%d", root->val);
    printf("(");
    in_order_node(root->next[0]);
    printf(",");
    in_order_node(root->next[1]);
    printf(")");
    return ;
}

void in_order(Tree *tree) {
    printf("tree(%d) : ", tree->n);
    in_order_node(tree->root);
    printf("\n");
    return ;
}

void clear_node(Node *root) {
    if (root == NULL) return ;
    clear_node(root->next[0]);
    clear_node(root->next[1]);
    free(root);
    return ;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

int main() {
    #define max_op 20
    Tree *tree = init_tree();
    int op, ind, val;
    for (int i = 0; i < max_op; ++i) {
        val = rand() % 100;
        printf("insert %d to list  = %d\n", val, insert(tree, val));
        in_order(tree);
    }
    #undef max_op
    return 0;
}
