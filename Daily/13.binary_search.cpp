/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 03 May 2020 02:19:28 PM CST
 ************************************************************************/

#include<cstdio>
#include<algorithm>

int num(int n) {
    return n;
}

int binary_search(int (*arr)(int), int x, int n) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr(mid) == x) return mid;
        else if (arr(mid) > x) r = mid - 1;
        else l = mid  + 1;
    }
    return -1;
}

int binary_2(int (*arr)(int), int l, int r, int x) {

    int mid = (l + r) >> 1;
    if (arr(mid) == x) return mid;
    if (l > r) return -1;
    if (arr(mid) > x) r = mid - 1;
    else l = mid + 1;
    return binary_2( arr, l, r, x);
}

int main() {
    int n, x, id, *arr;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }    
    printf("\n");
    while (~scanf("%d", &x) ) {
        id = binary_2(num, 0, n - 1, x);
        printf("serach %d = %d\n", x, id);
    }
    return 0;
}
