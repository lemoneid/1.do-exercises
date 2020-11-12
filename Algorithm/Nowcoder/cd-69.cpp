/*************************************************************************
	> File Name: cd-69.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 15时49分49秒
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
int n;

int main() {
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long range = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= range + 1) {
            range += arr[i];
        } else {
            cout << range + 1 << endl;
            return 0;
        }
    }
    cout << range + 1 << endl;
    return 0;
}
