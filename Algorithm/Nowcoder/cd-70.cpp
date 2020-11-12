/*************************************************************************
	> File Name: cd-70.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 16时09分18秒
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
long long n, k;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    int touch = 0, need = 0;
    for (int i = 0; i < n; ++i) {
        if (touch >= k) break;
        while (arr[i] > touch + 1) {
            touch += touch + 1; 
            need++;
        }
        touch += arr[i];
    }
    
    while (touch < k) {
        touch += touch + 1;
        need++;
    }
    cout << need << endl;
    return 0;
}
