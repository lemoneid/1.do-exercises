/*************************************************************************
    > File Name: 13.unstable_sort.cpp
    > Author: wei 
    > Mail: 1931248856@qq.com
    > Created Time: 2020年10月10日 星期六 20时34分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s\t= ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

void select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[ind] > arr[j]) ind = j;
        }
        swap(arr[ind], arr[i]);
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] > z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf(" %d", num[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 25
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, select_sort, num, max_op);
    TEST(arr, max_op, quick_sort, num, 0, max_op - 1);
    return 0;
}
