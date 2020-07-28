/*************************************************************************
	> File Name: 14.quick_sort.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月05日 星期日 18时11分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000000 
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap (num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ;
}

int arr[MAX_N + 5];

void init_arr(int *num, int n) {
    for (int i = 0; i < n; ++i) arr[i] = n - i;
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    return ;
}

int main () {
    init_arr(arr, MAX_N);
    quick_sort(arr, 0, MAX_N - 1);
    output(arr, MAX_N);
    return 0;
}
