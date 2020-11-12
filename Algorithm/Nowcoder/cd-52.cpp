# include <bits/stdc++.h>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

BST * input_BST()
{
    int n, fa, lch, rch, val;
    scanf("%d%d", &n, &val);
    BST * root, * new_node;
    map<int, BST *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[fa] = new_node;
            new_node->val = fa;
            if (fa == val) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}

double_list_node *getNewNode(int val) {
    double_list_node *p = (double_list_node *)malloc(sizeof(double_list_node));
    p->val = val;
    p->pre = NULL;
    p->next = NULL;
    return p;
}

void print_double_list(double_list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void preorder(BST *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    preorder(root->lch);
    preorder(root->rch);
}

void inorder(BST *root) {
    if (root == NULL) return;
    inorder(root->lch);
    printf("%d ", root->val);
    inorder(root->rch);
}

void lastorder(BST *root) {
    if (root == NULL) return ;
    lastorder(root->lch);
    lastorder(root->rch);
    printf("%d ", root->val);
}

int main ()
{
    BST * root = input_BST();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    lastorder(root);
    cout << endl;
    return 0;
}
