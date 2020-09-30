/*************************************************************************
	> File Name: 5.binary_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 22时05分50秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *init_tree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insert_node(Node *root, int val, int &flag) {
    if (root == NULL) {
        flag = 1;
        return getNewNode(val);
    }
    if (root->val == val) return root;
    if (val < root->val) {
        root->lchild = insert_node(root->lchild, val, flag);
    } else {
        root->rchild = insert_node(root->rchild, val, flag);
    }
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insert_node(tree->root, val, flag);
    tree->n += flag;
    return ;
}

void output_node(Node *root) {
    if (root == NULL) return;
    printf("%d", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("Tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return ;
}

void in_order_node(Node *root) {
    if (root == NULL) return ;
    in_order_node(root->lchild);
    printf("%d ", root->val);
    in_order_node(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    if (tree == NULL) return;
    in_order_node(tree->root);
}


void clear_node(Node *node) {
    if (node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return ;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Tree *tree = init_tree();
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    in_order(tree);
    clear_tree(tree);
    #undef max_op

    return 0;
}
