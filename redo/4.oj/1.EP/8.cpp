/*************************************************************************
	> File Name: 8.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 08时36分31秒
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
#define MAX_N 1000
char arr[MAX_N + 5];

int main() {
    int len = 0, ans = 0, pre = 1, zero = 0;
    while (~scanf("%s", arr + len)) len += strlen(arr);
    for (int i = 0; i < MAX_N; i++) {
        arr[i] -= '0'; 
        if (arr[i]) pre *= arr[i];
        else zero++;
        if (i < 13) continue;
        if (arr[i - 13]) pre /= arr[i - 13];
        else zero--;
        if (pre > ans && !zero) ans = max(ans, pre);
    }
    cout << ans << endl;
    return 0;
}
