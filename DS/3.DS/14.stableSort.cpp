/*************************************************************************
	> File Name: 14.stableSort.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月22日 星期五 12时00分30秒
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
#include <ctime>
using namespace std;
#define TEST(arr, n, func, args...) {\
    int *num = new int[n];\
    memcpy(num, arr, sizeof(int) * n);\
    printf("%s \t = ", #func);\
    func(num, args);\
    output(num, n);\
    delete[] num;\
}

int *init(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; 
    }
    return arr;
}

void output(int *arr, int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << "]" << endl;
}

void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag) break;
    }
    return ;
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
    int *num = new int[r - l + 1];
    int x = l, y = mid + 1, p = 0;
    while (x <= mid || y <= r) {
        if (y > r || x <= mid && arr[x] < arr[y]) {
            num[p++] = arr[x++];
        } else {
            num[p++] = arr[y++];
        }
    }
    memcpy(arr + l, num, sizeof(int) * (r - l + 1));
    delete[] num;
    return ;
}

void select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int cur = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[cur]) cur = j;
        }
        swap(arr[cur], arr[i]);
    } 
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, val = arr[l];
    while (x < y) {
        while (x < y && arr[y] > val) y--;
        if (x < y) swap(arr[x++], arr[y]);
        while (x < y && arr[x] < val) x++;
        if (x < y) swap(arr[y--], arr[x]);
    }
    arr[x] = val;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
    return ;
}

void downUpdate(int *arr, int idx, int n) {
    while ((idx << 1) <= n) {
        int cur = idx, l = idx << 1, r = idx << 1 | 1;
        if (arr[cur] < arr[l]) cur = l;
        if (r <= n && arr[cur] < arr[r]) cur = r;
        if (cur == idx) break;
        swap(arr[cur], arr[idx]);
        idx = cur;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i > 0; i--) {
        downUpdate(arr, i, n);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        downUpdate(arr, 1, i - 1);
    }
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = init(max_op);
    printf("%s \t = ", "raw_arr");
    output(arr, max_op);
    TEST(arr, max_op, insert_sort, max_op);
    TEST(arr, max_op, bubble_sort, max_op);
    TEST(arr, max_op, merge_sort, 0, max_op - 1);
    TEST(arr, max_op, select_sort, max_op);
    TEST(arr, max_op, quick_sort, 0, max_op - 1);
    TEST(arr, max_op, heap_sort, max_op);
    #undef max_op
    return 0;
}
