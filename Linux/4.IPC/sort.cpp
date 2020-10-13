/*************************************************************************
	> File Name: sort.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月11日 星期日 18时10分08秒
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

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp; \
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s\t= ", #func);\
    func(num, args);\
    output(num, n);\
    free(num);\
}


int insert_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
    return 1;
}

int bubble_sort(int *arr, int n) {
    int times = 1;
    for (int i = 1; times && i < n; ++i) {
        times = 0;
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            times++;
        }
    }
    return 1;
}

int merge_sort(int *arr, int l , int r) {
    if (r - l <= 1) {
        if (r - l == 1 && arr[r] < arr[l]) {
            swap(arr[r], arr[l]);
        }
        return 1;
    }
    int mid =  (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int p1 = l, p2 = mid + 1, ind = 0;
    int *tmp =  (int *)malloc(sizeof(int) * (r - l + 1));
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && arr[p1] < arr[p2]) tmp[ind++] = arr[p1++];
        else tmp[ind++] = arr[p2++];
    }
    memcpy(arr + l, tmp, sizeof(int) * (r - l + 1));
    free(tmp);
    return 1;
}

int select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[ind] <= arr[j]) continue;
            ind = j;
        }
        swap(arr[ind], arr[i]);
    }
    return 1;
}

int quick_sort(int *arr, int l, int r) {
    if (l >= r) return 0;
    int x = l, y = r, z = arr[l];
    while (x  < y) {
        while (x < y && arr[y] > z) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] < z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
    return 1;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int *init(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    while (n--) arr[n] = rand() % 100;
    return arr;
}

void downUpdate(int *arr, int ind, int n) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind ) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

int heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i > 0; --i) {
        downUpdate(arr, i, n);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        downUpdate(arr, 1, i - 1);
    }
    return 1;
}


int main() {
    srand(time(0));
    #define max_op 20
    int *arr = init(max_op);
    TEST(arr, max_op, insert_sort, max_op);
    TEST(arr, max_op, bubble_sort, max_op);
    TEST(arr, max_op, merge_sort, 0, max_op - 1);
    TEST(arr, max_op, select_sort, max_op);
    TEST(arr, max_op, quick_sort, 0, max_op - 1);
    TEST(arr, max_op, heap_sort, max_op);
    #undef max_op
    return 0;
}
