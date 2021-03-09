/*************************************************************************
	> File Name: build_heap.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 15时47分17秒
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

struct Node {
    char *str;
    struct Node *next;
};

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *getNode(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = 2 * n;
    h->data = (Node **)malloc(sizeof(Node *) * h->size);
    return h;
}

int BKDRHash(char *str) {
    int hash = 0, seed = 31;
    for (int i = 0; str[i]; i++) {
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *head = h->data[ind];
    h->data[ind] = getNode(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
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
