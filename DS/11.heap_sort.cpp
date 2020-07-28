/*************************************************************************
	> File Name: 11.heap_sort.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月04日 星期六 18时40分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
} 

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap (arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i > 0; --i) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(const int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; ++i) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; ++i) {
        arr[i] = rand() % 100;
    }       
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    free(arr);
    return 0;
}
