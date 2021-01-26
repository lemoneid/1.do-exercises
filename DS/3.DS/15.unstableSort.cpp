/*************************************************************************
	> File Name: 15.unstableSort.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月22日 星期五 17时34分48秒
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
    p->str = str ? strdup(str) : nullptr;
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *p = (HashTable *)malloc(sizeof(HashTable));
    p->size = n * 2;
    p->data = (Node **)malloc(sizeof(Node *) * p->size);
    return p;
}

int BKDRHash(char *str) {
    int hash = 0, seed = 31;
    for (int i = 0; str[i]; ++i) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int idx = hash % h->size;
    Node *head = h->data[idx];
    while (head && strcmp(str, head->str)) head = head->next;
    return head != nullptr;
}

bool insert(HashTable *h, char *str) {
    if (search(h, str)) return false;
    int hash = BKDRHash(str);
    int idx = hash % h->size;
    h->data[idx] = init_node(str, h->data[idx]);
    return true;
}

void clear_node(Node *head) {
    if (!head) return ;
    Node *p = nullptr;
    while (head) {
        p = head->next;
        free(head);
        head = p;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (!h) return ;
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
