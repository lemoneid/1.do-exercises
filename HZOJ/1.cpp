/*************************************************************************
	> File Name: 1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 16时24分33秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s1[1005], s2[1005];
    fgets(s1, 1005, stdin);
    fgets(s2, 1005,stdin);
    int ans = 0;
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i <= l1 - l2; i++) {
        if (strncmp(s2, &s1[i], l2) == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
