#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;
typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct Tree {
   Node *root;
   int n; 
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->val = val;
    return p;
}

Tree *getNewTree() {
    Tree * t = (Tree *)calloc(sizeof(Tree), 1);
    return t;
}

Node *insertNode(Node *root, int val, int &flag) {
    if (!root) return getNewNode(val);
    if (root->val == val) {
        flag = 0; 
        return root;
    }
    if (root->val < val) {
        root->right = insertNode(root->right, val, flag);
    } else {
        root->left = insertNode(root->left, val, flag);
    }
    return root;
}

bool insert(Tree *t, int val) {
    if (!t) return false;
    int flag = 1;
    t->root = insertNode(t->root, val, flag);
    t->n += flag;
    return flag == 1;
}

Node *getMostLeft(Node *root) {
    while (root && root->left) root = root->left;
    return root;
}

Node *popNode(Node *root, int val, int &flag) {
    if (!root) return root;
    if (root->val == val) {
        if (!flag) flag = 1;
        Node *p = getMostLeft(root->right);
        root->val = p->val;
        root->right = popNode(root->right, root->val, flag);
    } else if (root->val < val) {
        root->right = popNode(root->right, val, flag);
    } else {
        root->left = popNode(root->left, val, flag);
    }
    return root;
}

bool pop(Tree *t, int val) {
    if (!t) return false;
    int flag = 0;
    t->root = popNode(t->root, val, flag);
    t->n -= flag;
    return flag == 1;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%d", root->val);
    printf("(");
    outputNode(root->left);
    printf(",");
    outputNode(root->right);
    printf(")");
    return ;
}

void output(Tree *t) {
    if (!t) return ;
    printf("Tree(%d) = ", t->n);
    outputNode(t->root);
    printf("\n");
    return ;
}

void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->left);
    clearNode(root->right);
    free(root);
    return ;
}

void clearTree(Tree *t) {
    if (!t) return ;
    clearNode(t->root);
    free(t);
    return ;
}


void in_order_node(Node *root) {
    if (root == NULL) return ;
    in_order_node(root->left);
    printf("%d ", root->val);
    in_order_node(root->right);
    return ;
}

void in_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}


void outputTable(Node *root, ostringstream &out) {
    if (!root) return ;
    out << root->val << " ";
    out << "( ";
    outputTable(root->left, out);
    out << ", ";
    outputTable(root->right, out);
    out << ") "; 
    return ;
}


int main() {

    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 10
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        printf("insert(%d) : ", val);
        insert(tree, val);
        output(tree);
    }
    ostringstream out;
    outputTable(tree->root, out);
    cout << "out : " << out.str() << endl;
    ofstream fp("./input");
    if (fp.is_open()) {
        fp << out.str() << endl;
    }
    in_order(tree);
    #undef max_op
    clearTree(tree);
    return 0;
}

