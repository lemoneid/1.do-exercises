/*************************************************************************
	> File Name: sort.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 19时32分31秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

const int max_n = 100;

int arr[max_n + 5] = {0};

bool cmp(int a, int b) {
    return a > b;
}

void output(int n) {
    for (int i = 0; i < n; ++i) {
        !i || cout << " ";
        cout << arr[i];
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }
    output(n);
    sort(arr, arr + n, cmp);
    output(n);
    return 0;
}
