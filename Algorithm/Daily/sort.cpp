/*************************************************************************
    > File Name: sort.cpp
    > Author: yanzhiwei
    > Mail: 1931248856@qq.com
    > Created Time: 2021年02月24日 星期三 20时33分22秒
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

#define TEST(arr, n, func, args...) {\
    int *temp = (int *)malloc(sizeof(int ) * n);\
    memcpy(temp, arr, sizeof(int *) * n);\
    printf("normal : \t");\
    output(arr, n);\
    printf("%s : \t", #func);\
    func(temp, args);\
    output(temp, n);\
    free(temp);\
}

void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                continue;
            }
            break;
        }
    }
}

void bubble_sort(int *arr, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                times = 1;
            }
        }
    }
}

void merge_sort(int *arr, int l, int r) {
    if (r <= l) return ;
    if (r - l == 1) {
        if (arr[l] > arr[r]) swap(arr[l], arr[r]);
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int x = l, y = mid + 1, p = 0;
    while (x <= mid || y <= r) {
        if (y > r || x <= mid && arr[x] <= arr[y]) {
            temp[p++] = arr[x++];
        } else {
            temp[p++] = arr[y++];
        }
    }
    memcpy(arr + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

void quick_sort(int *arr, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= z) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
    return ;
}

int select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = 1; j < n; j++) {
            if (arr[j] < arr[ind]) {
                ind = j;
            }
        }
        swap(arr[ind], arr[i]);
    }
}

void downUpdata(int *arr, int ind, int n) {
    while (ind << 1 <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i > 0; i--) {
        downUpdata(arr, i, n);
    }
    for (int i = n; i > 0; i--) {
        swap(arr[1], arr[i]);
        downUpdata(arr, 1, i - 1);
    }
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100], n = 20;
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
    TEST(arr, n, insert_sort, n);
    TEST(arr, n, bubble_sort, n);
    TEST(arr, n, select_sort, n);
    TEST(arr, n, quick_sort, 0, n - 1);
    TEST(arr, n, merge_sort, 0, n - 1);
    TEST(arr, n, heap_sort, n);
    return 0;
}
