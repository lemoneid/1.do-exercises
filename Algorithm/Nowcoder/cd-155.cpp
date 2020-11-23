/*************************************************************************
	> File Name: cd-154.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 21时05分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];
int n, k;
unordered_map<int, int> mmap;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        mmap[arr[i]]++;
    }
    int flag = 0, p = n / k;
    for (int i = 0; i < n; ++i) {
        if (mmap[arr[i]] <= p) continue;
        flag && cout << " ";
        cout << arr[i];
        mmap[arr[i]] = 0;
        flag = 1;
    }
    if (!flag) cout << -1 << endl;
    return 0;
}
