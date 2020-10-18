/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月11日 星期日 15时21分58秒
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
using namespace std;

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
    h->size = n * 2;
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

int BKDRHash(char *str) {
    int hash = 0, seed = 31;
    for (int i = 0; str[i]; ++i) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *head = h->data[ind];
    while (head && strcmp(str, head->str)) head = head->next;
    return head != NULL;
}

int insert(HashTable *h, char *str) {
    if (search(h, str)) return 0;
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

void clear_node(Node *head) {
    if (head == NULL) return ;
    Node *p = head, *q;
    while(p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; ++i) clear_node(h->data[i]);
    free(h);
    return ;
}

int main() {
    #define max_n 1000
    HashTable *h = init_hashtable(max_n + 5);
    char *str = (char *)malloc(sizeof(char) * (max_n + 5));
    int op;
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0 : 
                printf("%s insert to the HashTable = %d\n", str, insert(h, str));
            break;
            default : 
                printf("search %s from the HashTable = %d\n", str, search(h, str));
            break;
        }
    }
    clear_hashtable(h);
    #undef max_n

    return 0;
}
