/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 22时14分30秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

typedef struct Queue {
    int *data;
    int size, length, tail, head;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)calloc(n, sizeof(int));
    q->size = n;
    q->length = q->tail = q->head = 0;
    return q;
}

int empty(Queue *q) {
    return q->length == q->size;
}

int front(Queue *q) {
    return q->data[q->head];
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->size == q->length) return 0;
    q->data[q->tail++] = val;
    if (q->tail == q->size)  q->tail = 0;
    q->length += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->size) q->head = 0;
    q->length -= 1 ;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return ;
    for (int i = 0, j = q->head; i < q->length; ++i) {
        i && printf(",");
        printf("%d", q->data[(i + j) % q->size]);
    }   
    printf("\n");
    return ;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    Queue *q = init_queue(10);
    int op, val;
    for (int i = 0; i < 20; ++i) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
                printf("earse a item at %d from list = %d\n", front(q), pop(q));
                break;
            case 1 : 
            case 2 :
            case 3 :
                printf("insert %d to list  = %d\n", val, push( q,val));
                break;
        }
        output(q);

    }

    return 0;
}
