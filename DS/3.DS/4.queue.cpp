#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, size, length; 
} Queue;

Queue *init(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->size = size;
    q->head = q->tail = q->length = 0;
    return q;
}

bool empty(Queue *q) {
    return q->length == 0;
}

int front(Queue *q) {
    if (empty(q)) return -1;
    return q->data[q->head];
}

bool expand(Queue *q) {
    int extra_size = q->size;
    int *p = nullptr;
    while (extra_size) {
        p = (int *)malloc(sizeof(int) * (q->size + extra_size));
        if (p) break;
        extra_size >>= 1;
    }
    if (!p) return false;
    for (int i = 0; i < q->length; ++i) {
        p[i] = q->data[(q->head + i) % q->size];
    }
    free(q->data);
    q->data = p;
    q->size += extra_size;
    q->head = 0;
    q->tail = q->length;
    return true;
}

bool push(Queue *q, int val) {
    if (!q) return false;
    if (q->length == q->size) {
        if (!expand(q))return false;
        cout << "expand success!" << endl;
    }
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail = 0;
    q->length++;
    return true;
}

bool pop(Queue *q) {
    if (!q || empty(q)) return false;
    q->head++;
    if (q->head == q->size) q->head = 0;
    q->length--;
    return true;
}

void output(Queue *q) {
    printf("Queue(%d) = [", q->length);
    ///*
    for (int i = q->head; i != q->tail; i = (i + 1) % q->size) {
        i != q->head && printf(", ");
        printf("%d", q->data[i]);
    }
    //*/
    /*
    for (int i = 0; i < q->length; ++i) {
        i && printf(", ");
        printf("%d", q->data[(q->head + i) % q->size]);
    }
    */
    printf("]\n\n");
    return ;
}

void clear(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    #define max_op 40
    srand(time(0));
    Queue *q = init(1);
    for (int i = 0; i < max_op; ++i) {
        int val  = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0 : 
            case 1 :
            case 2 : {
                printf("push %d to the Queue = %d\n", val, push(q, val));
            } break;
            case 3 : {
                int head = front(q);
                printf("pop %d from the Queue = %d\n", head, pop(q));
            } break;
        }
        output(q);
    }
    clear(q);
    #undef max_op
    return 0;
}
