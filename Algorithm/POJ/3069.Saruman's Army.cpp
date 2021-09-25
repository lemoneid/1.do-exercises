/*************************************************************************
	> File Name: 3069.Saruman's Army.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月25日 星期六 17时42分03秒
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

const int MAX_N = 1000;
int arr[MAX_N + 5];

int solve(int n, int r) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int index = 0, count = 0;
    while (index < n) {
        int s = arr[index++];
        while (index < n && s + r >= arr[index]) index++;
        int p = arr[index - 1];
        while (index < n && p + r >= arr[index]) index++;
        count++;
    }
    return count;
}

int main() {
    int n, r;
    while (cin >> r >> n) {
        if (n == -1 || r == -1) break;
        cout << solve(n, r) << endl;
    }
}
