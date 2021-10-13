/*************************************************************************
	> File Name: 14.extend_sort.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年10月12日 星期二 19时26分33秒
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

void insertI(int *arr, int h, int i) {
    int val = arr[i], k;
    for (k = i - h; k >= 0 && val < arr[k]; k -= h) {
        arr[k + h] = arr[k];
    }
    arr[k + h] = val;
    return ;
}

int shell_sort(int *arr, int n) {
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            insertI(arr, h, i);
        }
    }
    return 1;
}


void merge(int *arr, int left, int mid , int right) {
    int *temp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= mid) temp[k++] = arr[j++];
    for (i = 0; i < k; i++) {
        arr[left++] = temp[i];
    }
    delete[] temp;
    return ;
}

int merge_sort_iter(int *arr, int n) {
    for (int i = 1; i < n; i += i)  {
        int left = 0;
        int mid = left + i - 1;
        int right = mid + i;
        while (right < n) {
            merge(arr, left, mid, right);
            left = right + 1;
            mid = left + i - 1;
            right = mid + i;
        }
        if (left < n && mid < n) {
            merge(arr, left, mid, n - 1);
        }
    }
    return 1;
}

int count_sort(int *arr, int n) {
    int mmax = arr[0];
    int mmin = arr[0];
    for (int i = 1; i < n; i++) {
        mmax = max(mmax, arr[i]);
        mmin = min(mmin, arr[i]);
    }
    int size = mmax - mmin + 1;
    int *temp = new int[size];
    for (int i = 0; i < n; i++)  {
        temp[arr[i] - mmin]++;
    }
    int k = 0;
    for (int i = 0; i <= mmax; i++) {
        for (int j = temp[i]; j > 0; j--) {
            arr[k++] = i + mmin;
        }
    }
    delete[] temp;
    return 1;
}

int main() {

    return 0;
}
