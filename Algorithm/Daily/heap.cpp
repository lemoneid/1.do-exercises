/*************************************************************************
	> File Name: heap.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 15时37分09秒
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

struct priority_queue {
    int *data;
    int cnt, size;
};

priority_queue *init(int n) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->data = (int *)malloc(sizeof(int) * (n + 1));
    p->size = n;
    p->cnt = 0;
}

int empty(priority_queue *p) {
    return p->cnt == 0;
}

int top(priority_queue *p) {
    return p->data[1];
}

bool push(priority_queue *p, int val) {
    if (!p) return false;
    if (p->cnt == p->size) return false;
    p->data[++p->cnt] = val;
    int ind = p->cnt;
    while (ind >> 1 && p->data[ind] > p->data[ind >> 1]) {
        swap(p->data[ind], p->data[ind >> 1]);
        ind >>= 1;
    }
    return true;
}

bool pop(priority_queue *p) {
    if (!p) return false;
    if (empty(p)) return false;
    p->data[1] = p->data[p->cnt--];
    int ind = 1, n = p->cnt, *arr = p->data;
    while (ind << 1 <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return true;
}

void clear(priority_queue *p) {
    if (!p) return;
    free(p->data);
    free(p);
    return ;
}

int main() {


    return 0;
}
