/*************************************************************************
	> File Name: oj-514.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 21时11分26秒
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

const int MAX_N = 800;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
inline int getCnt(int val) {
    if (val == 0) return arr[0];
    int cnt = 0;
    while (val) {
        cnt += arr[val % 10];
        val /= 10;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j++) {
            if (getCnt(i) + getCnt(j) + getCnt(i + j) == n - 4) {
                ans += (i == j ? 1 : 2);
            }
        }
    } 
    cout << ans << endl;

    return 0;
}
