/*************************************************************************
	> File Name: 16.hash_table.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 21时59分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

//开放定值法，拉链法-在后面接链表，再哈希，建立公共溢出区

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

//aphash
int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; ++i) hash = hash *seed + str[i];
    return hash & 0x7fffffff;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

int insert(HashTable *h, char *str) {
    if (search(h, str)) return 0;
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return;
    for (int i = 0; i < h->size; ++i) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op; 
    #define max_op 100
    char str[max_op + 5] = {0};
    HashTable *h = init_hashtable(max_op + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op)  {
            case 0 :
                printf("insert %s to HashTable = %d\n", str, insert(h, str));
                break;
            default : 
                printf(" search %s in HashTable = %d\n", str ,search(h, str));
                break;
        }
    }
    return 0;
}
