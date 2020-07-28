/*************************************************************************
	> File Name: 13.unstable_sort.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月05日 星期日 16时30分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b =__temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (num[j] < num[ind]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y  && num[y] > z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y  && num[x] < z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
}

void randint(int *arr, int n) {
    while (n--) arr[n] = rand() % 100;
    return ;
}

void output(int *arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20 
    int arr[MAX_OP];
    randint(arr, MAX_OP);
    TEST(arr, MAX_OP, select_sort, num, MAX_OP);
    TEST(arr, MAX_OP, quick_sort, num, 0, MAX_OP - 1);
    return 0;
}
