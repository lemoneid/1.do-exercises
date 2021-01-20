/*************************************************************************
	> File Name: 12.heap_sort.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月18日 星期一 15时36分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

void output(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void downUpdata(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int cur = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[cur] < arr[l]) cur = l;
        if (r <= n && arr[cur] < arr[r]) cur = r;
        if (ind == cur) break;
        swap(arr[ind], arr[cur]);
        ind = cur;
    } 
    return ;
}
 
void heap_sort(int *arr, int n) {
    if (!arr || n == 1) return ;
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdata(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdata(arr, i - 1, 1);
    }
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *)malloc(sizeof(int) * max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);


    return 0;
}
