/*************************************************************************
	> File Name: oj-504.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月10日 星期三 22时49分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    char n[250] = {0};
    int len, cnt;
    cin >> n >> cnt;
    len = strlen(n);
    while (cnt--) {
        int i = 0;
        while (n[i] <= n[i + 1]) ++i;
        while (i < len - 1) {
            n[i] = n[i + 1];
            i += 1;
        }
        len -= 1;
    }
    int flag = 1;
    for (int i = 0; i < len; ++i) {
        if (n[i] == '0' && i < len - 1 && flag) continue;
        cout << n[i];
        flag = 0;
    }
    return 0;
}
