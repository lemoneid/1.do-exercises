/*************************************************************************
	> File Name: 11.head_sort.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月08日 星期四 18时58分27秒
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}

void downUpdate(int *arr, int n, int idx) {
    while ((idx << 1) <= n) {
        int tmp = idx, l = idx << 1, r = idx << 1 | 1;
        if (arr[l] > arr[tmp]) tmp = l;
        if (r <= n && arr[r] > arr[tmp]) tmp = r;
        if (tmp == idx) break;
        swap(arr[tmp], arr[idx]);
        idx = tmp;
    }
}

void heap_sort(int *arr, int n) {
    arr -= 1; // 偏移一位,从1开始操作,符合习惯
    for (int i = n >> 1; i >= 1; --i) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }   
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; ++i) {
        i  && printf(",");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *)malloc(sizeof(int) * max_op);
    for (int i = 0; i < max_op; ++i) {
        arr[i] = rand() % 100;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    return 0;
}
