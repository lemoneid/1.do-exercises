/*************************************************************************
	> File Name: 11.priority_queue.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月18日 星期一 15时22分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int size) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->size = size;
    q->data = (int *)malloc(sizeof(int) * (q->size + 1));
    q->cnt = 0;
    return q;
}

bool empty(priority_queue *q) {
    if (!q) return true;
    return q->cnt == 0;
}

int top(priority_queue *q) {
    if (empty(q)) return -1;
    return q->data[1];
}

bool push(priority_queue *q , int val) {
    if (!q) return false;
    if (q->cnt == q->size) return false;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return true;
}

bool pop(priority_queue *q) {
    if (!q) return false;
    if (empty(q)) return false;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int cur = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[ind] < q->data[l]) cur = l;
        if (r <= q->cnt && q->data[cur] < q->data[r]) cur = r;
        if (ind == cur) break;
        swap(q->data[ind], q->data[cur]);
        ind = cur;
    }
    return true;
}

void clear(priority_queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    clear(q);

    return 0;
}
