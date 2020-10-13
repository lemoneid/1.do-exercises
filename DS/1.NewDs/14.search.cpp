/*************************************************************************
	> File Name: 14.search.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 21时08分17秒
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
using namespace std;

double f( double x) {
    return -1 * x * x + 2 * x + 8;
}

double df(double x) {
    return -2 * x  +  2;
}

double three_search(double l, double r) {
    double m1, m2;
    while (r - l > 1e-5) {
        m1 = l + (r - l) / 3.0;
        m2 = r - (r - l) / 3.0;
        if (f(m1) <= f(m2)) l = m1;
        else r = m2;
    cout << m1 << " " << m2 << " " << (m1 + m2) / 2.0 << endl;
    } 
    cout << "l = " << l << " r = " << r << endl;
    cout << f(l) << " " << df(r) << endl;
    return (l + r) / 2.0;
}

//1111100000
int binary_search_1(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}
//000001111
int binary_search_2(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return tail;
}

int main() {
    int arr1[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr2[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    for (int i = 0; i < 10; ++i) {
        printf(" %d", arr1[i]);
    }
    printf("\n");
    printf("%d\n", binary_search_1(arr1, 10));
    for (int i = 0; i < 10; ++i) {
        printf(" %d", arr2[i]);
    }
    printf("\n");
    printf("%d\n", binary_search_2(arr2, 10));
    three_search(-100 , 100);
    return 0;
}
