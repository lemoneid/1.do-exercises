/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 14时54分03秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>

typedef struct Queue {
    int *data;
    int size, head, tail, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)calloc(n, sizeof(int));
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

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail = 0;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->size) q->head = 0;
    q->cnt -= 1;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->cnt; ++j) {
        j != 0 && printf(",");
        printf("%d", q->data[(i + j) % q->size]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(max_op);
    int op, val, tmp;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0 :
                printf("pop %d from Queue = %d\n", front(q), pop(q));
                break;
            case 1 :
            case 2 :
            case 3:
                printf("push %d to the Queue = %d\n",val, push(q, val));
        }
        output(q);
    }

    return 0;
}
