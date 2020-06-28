/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月20日 星期六 14时49分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int size, head, tail, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->size = n;
    q->head = q->tail = q->cnt = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int expand(Queue *q) {
    int extr_size = q->size;
    int *p;
    while (extr_size) {
        p = (int *)malloc(sizeof(int) * (q->size + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    for (int j = 0; j < q->cnt; ++j) {
        p[j] = q->data[(q->head + j) % q->size];
    }
    free(q->data);
    q->data = p;
    q->size += extr_size;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) {
        printf("\033[;31m expand : %d\033[0m\n\n", expand(q));
    }
    q->data[q->tail++] = val;
    if(q->tail == q->size) q->tail -= q->size;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue : [");
    for (int i = 0; i < q->cnt; ++i) {
        i != 0 && printf(", ");
        printf("%d", q->data[(q->head + i) % q->size]);
    }
    printf("]\n\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
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
