/*************************************************************************
	> File Name: 1.atoi.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 20时07分24秒
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

#ifdef _D
#define log(frm, args...) {\
    printf("[%s : %d] %s ", __func__, __LINE__, #args);\
    printf(frm, ##args);\
    printf("\n");\
}
#else
#define log(frm, args...)
#endif

int atoi(const char *str) {
    if (!str) return 0;
    const char *p = str;
    int flag = 0;
    while (*p == ' ') p++;
    if (*p == '-') flag = 1, p++;
    int num = 0;
    while (*p != '\0') {
        if (!(*p < '0' || *p > '9')) {
            num = num * 10 + *p - '0';
        }
        p++;
    }
    num *= flag ? -1 : 1;
    return num;
}

int main() {
    cout << atoi(" -ds123123 ");
    return 0;
}
