/*************************************************************************
        > File Name: double_array_trie.cpp
        > Author: yanzhiwei
        > Mail: 1931248856@qq.com
        > Created Time: 2021年02月24日 星期三 22时26分48秒
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
#include <queue>
using namespace std;
#define BASE 26
#define BEGIN_LETTER 'a'
#define has_child(data, ind, i) (abs(data[data[ind].base + i].check) == ind)

struct DANode {
    int base, check, fail;
    char *str;
};

struct Node {
    int flag; 
    char *str;
    struct Node *next[BASE];
};

int node_cnt = 0;
Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    node_cnt += 1;
    return p;
}

Node *insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (!p->next[ind]) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    p->str = strdup(str);
    cout << str << endl;
    return root;
}

int get_base(Node *node, DANode *data) {
    int base = 1, flag = 1;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            if (data[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}
int build(Node *node, DANode *data, int ind) {
    if (!node) return 0;
    if (node->flag) {
        data[ind].check = -data[ind].check;
        data[ind].str = node->str;
    }
    int base = get_base(node, data);
    cout << base << endl;
    data[ind].base = base;
    for (int i = 0; i < BASE; i++) {
        if (!node->next[i]) continue;
        data[base + i].check = ind;
    }
    int max_ind = 0;
    for (int i = 0; i < BASE; i++) {
        if (!node->next[i]) continue;
        int temp = build(node->next[i], data, base + i);
        max_ind = max(max_ind, temp);
    }
    return max_ind;
}

void build_ac(DANode *data, int i) {
    queue<int> que;
    data[1].fail = 0;
    que.push(1);
    while(!que.empty()) {
        int ind = que.front();
        que.pop();
        for (int i = 0; i < BASE; i++) {
            if (!has_child(data, ind, i)) continue;
            int p = data[ind].fail;
            while (p && !has_child(data, p, i)) p = data[p].fail;
            if (p == 0) p = 1;
            else p = data[p].base + i;
            int child = data[ind].base + i;
            data[child].fail = p;
            que.push(child);
        }
    }
}

void build_ac(DANode *data) {
    #define MAX_N 100000
    int *queue = (int *)malloc(sizeof(int) * MAX_N);
    int head = 0, tail = 0;
    data[1].fail = 0;
    queue[tail++] = 1;
    while (head < tail) {
        int ind = queue[head++];
        for (int i = 0; i < BASE; i++) {
            if (!has_child(data, ind, i)) continue;
            int p = data[ind].fail;
            while (p && !has_child(data, p, i)) p = data[p].fail;
            if (p == 0) p = 1;
            else p = data[p].base + i;
            data[data[ind].base + i].fail = p;
            queue[tail++] = data[ind].base + i;
        }
    }
    return ;
    #undef MAX_N
}

void search_ac(DANode *data, const char *str, int i) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        while (p && !has_child(data, p, ind)) p = data[p].fail;
        if (!p) p = 1;
        else p = data[p].base + ind;
        int q = p;
        while (q) {
            if (data[q].check < 0) cout << "find string : " <<  data[q].str << endl;
            q = data[q].fail;
        }
    }
}


void search_ac(DANode *data, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        while (p && !has_child(data, p, str[i] - BEGIN_LETTER)) p = data[p].fail;
        if (p == 0) p = 1;
        else p = data[p].base + str[i] - BEGIN_LETTER;
        int q = p;
        while (q) {
            if (data[q].check < 0) printf("find string : %s\n", data[q].str);
            q = data[q].fail;
        }
    }
    return ;
}

void output_da(DANode *data, int n) {
    for (int i = 1; i <= n; i++) {
        if (i - 1 && i % 5 == 1) printf("\n");
        printf("(%2d %2d %3d)    ", i, data[i].base, data[i].check);
    }
    printf("\n");
    return ;
}

void output_node(Node *root, char *buff, int k) {
    if (!root) return ;
    if (root->flag) {
        cout << buff << endl;
    }
    buff[k + 1] = 0;
    for (int i = 0; i < BASE; i++) {
        if (!root->next[i]) continue;
        buff[k] = i + BEGIN_LETTER;
        output_node(root->next[i], buff, k + 1);
    }
    return ;
}

int main() {
    Node *root = getNewNode();
    char buff[1000];
    #define INSERT_CNT 5
    root = insert(root, "hai");
    root = insert(root, "zei");
    root = insert(root, "ha");
    root = insert(root, "ab");
    root = insert(root, "ehz");
    output_node(root, buff, 0);
    cout << "output_node" << endl;
    DANode *data = (DANode *)calloc(sizeof(DANode), (INSERT_CNT * 100));
    int da_cnt = build(root, data, 1);
    cout << da_cnt << endl;
    build_ac(data);
    output_da(data, da_cnt);
    cout << "sasherhs" << endl;
    search_ac(data, "sasherhs");
    #undef INSERT_CNT 
    return 0;
}
