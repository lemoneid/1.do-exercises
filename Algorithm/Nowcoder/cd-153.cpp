/*************************************************************************
	> File Name: cd-153.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 20时32分13秒
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
int arr[MAX_N + 5], save[MAX_N + 5];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        save[i] = arr[i];
    }
    sort(arr, arr + n);
    int x = 0, y = n - 1;
    while (x <= y && arr[x] == save[x]) x++;
    while (x <= y && arr[y] == save[y]) y--;
    cout << y - x + 1 << endl;
    return 0;
}
