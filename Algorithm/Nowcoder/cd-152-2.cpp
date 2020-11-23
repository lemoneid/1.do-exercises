/*************************************************************************
	> File Name: cd-152-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 19时20分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5];

int getMedian(int *arr, int l, int r) {
    sort(arr + l, arr + r + 1);
    int sum = l + r;
    int mid = sum / 2 + sum % 2;
    return arr[sum];
}

int parition(int *arr, int l, int r, int val) {
    int pos = 0;
    for (int i = l; i <= r; ++i) {
        if (arr[i] != val) continue;
        pos = i;
        break;
    }
    swap(arr[pos], arr[l]);
    int x = l, y = r;
    while (x < y) {
        while (x < y && arr[y] >= val) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= val) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = val;
    return x;
}

int getLessKth(int *arr, int l, int r, int k) {
    if (l == r) return arr[l];
    int len = r - l + 1;
    int num = len / 5;
    num += len % 5 == 0 ? 0 : 1;
    int *midArr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; ++i) {
        int begin = l + i *  5;
        int end = min(r, begin + 5);
        midArr[i] = getMedian(arr, begin, end);
    }
    int pivot = getLessKth(midArr, 0, num - 1, num / 2);
    free(midArr);
    int id = parition(arr, l, r, pivot);
    int rank = id - l + 1;
    if (rank == k) {
        return arr[id];
    }
    if (rank > k) {
        return getLessKth(arr, l, id - 1, k);
    } else {
        return getLessKth(arr, id + 1, r, k - rank);
    }
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < m; ++i) {
        i && printf(" ");
        printf("%d", getLessKth(arr, 0, n - 1, i + 1));
    }
    return 0;
}
