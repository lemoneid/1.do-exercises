/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月08日 星期四 19时23分27秒
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}

typedef struct priority_queue{
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->size == q->cnt) return 0;
    q->data[++q->cnt] = val;
    int idx = q->cnt;
    while (idx >> 1) {
        int tmp = idx, l = idx >> 1, r = idx >> 1 | 1;
        if (q->data[tmp] > q->data[l]) tmp = l;
        if (r && q->data[tmp] > q->data[r]) tmp = r;
        if (tmp == idx) break;
        swap(q->data[idx], q->data[tmp]);
        idx = tmp;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int idx = 1;
    while ((idx << 1) <= q->cnt) {
        int tmp = idx, l = idx << 1, r = idx << 1 | 1;
        if (q->data[tmp] < q->data[l]) tmp = l;
        if (r && q->data[tmp] < q->data[r]) tmp = r;
        if (tmp == idx) break;
        swap(q->data[idx], q->data[tmp]);
        idx = tmp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}


int main() {
    srand(time(0));
    #define max_op 25
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        push(q, val);
        printf("push %d to priority_queue \n", val);
    }
    for (int i = 0; i < max_op; ++i) {
        printf("%d ", top(q));
        pop(q);
    }
    #undef max_op
    return 0;
}
