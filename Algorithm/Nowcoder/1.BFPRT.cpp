/*************************************************************************
	> File Name: BFPRT.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 16时13分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX_N  = 100000;

void insertSort(int *arr, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        for (int j = i; j > l && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

int getMedian(int *arr, int l, int r) {
    insertSort(arr, l, r);
    int sum = l + r;
    int mid = sum / 2 + sum % 2;
    return arr[mid];
}

int partition(int *arr, int l, int r, int val) {
    int pos = 0;
    for (int i = l; i <= r; ++i) {
        if (arr[i] != val) continue;
        pos = i;
        break;
    }
    swap(arr[pos], arr[l]);
    int base = arr[l], x = l, y = r;
    while (x < y) {
        while (x < y && arr[y] >= base) y--;
        if (x < y) swap(arr[x++], arr[y]);
        while (x < y && arr[x] <= base) x++;
        if (x < y) swap(arr[y--], arr[x]);
    }
    arr[x] = base;
    return x;
}

int select(int *arr, int l, int r, int kth) {
    if (l == r) return arr[l];
    int len = r - l + 1;
    int num = len / 5;
    num += len % 5 == 0  ? 0 : 1;
    int *midArr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < num; ++i) {
        int begin = l + i * 5;
        int end = min(r, begin + 5);
        midArr[i] = getMedian(arr, l, r); 
    }
    int pivot = select(midArr, 0, num - 1, num / 2);
    free(midArr);
    int id = partition(arr, l, r, pivot);
    int rank = id - l + 1;
    if (rank == kth) return arr[id];
    if (rank > kth) return select(arr, l, id - 1, kth);
    else return select(arr, id + 1, r, kth - rank);
}

int getMinKth(int *arr, int n, int kth) {
    int ans = select(arr, 0, n - 1, kth);
    return ans;
}

int main() {
    int n, m;
    int *arr = (int *)malloc(sizeof(int) * (MAX_N + 5));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = 1; i <= m; ++i) {
        i != 1 && printf(" ");
        printf("%d", getMinKth(arr, n, i));
    }
    free(arr);
    return 0;
}
