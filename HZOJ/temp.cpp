/*************************************************************************
	> File Name: temp.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 23 Sep 2020 07:55:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 200

int pri[MAX_N], arr[MAX_N];
int main() {
    int n, m, l  = 0, r = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        r += arr[i];
    }
    
    while (l < r) {
        int mid = (l + r) >> 1; 
    }

    return 0;
}
