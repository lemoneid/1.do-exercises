/*************************************************************************
	> File Name: test1.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月08日 星期四 19时40分36秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>

#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}

void downUpdate(int *arr, int n, int idx) {
    while ((idx << 1) <= n) {
        int tmp = idx, l = idx << 1, r = idx << 1 | 1;
        if (arr[tmp] < arr[l]) tmp = l;
        if (r && arr[tmp] < arr[r]) tmp = r;
        if (tmp == idx) break;
        swap(arr[tmp], arr[idx]);
        idx = tmp;

    }
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; --i) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }

}


int main() {


    return 0;
}
