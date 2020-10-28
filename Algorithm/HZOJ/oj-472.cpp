/*************************************************************************
	> File Name: oj-472.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月24日 星期日 06时40分12秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
const int max_m = 1000;
const int max_n = 8;
char str_m[max_m + 5], str_n[max_n + 5];
int num_m[max_m + 5], num_n[max_n + 5], ans[max_m + 5];

void carry(int *arr) {

}

void solve(const char *str1, const char *str2) {
    memset(ans, 0, sizeof(ans));
    int len_m = strlen(str1), len_n =  strlen(str2);
    for (int i = 0; str1[i]; ++i) num_m[len_m - i] = str1[i] - '0';
    for (int i = 0; str2[i]; ++i) num_n[len_n - i] = str2[i] - '0';
    num_m[0] = len_m, num_n[0] = len_n;
    
}

int main() {
    while (~scanf("%s%s", str_n, str_m)) {
        solve(str_m, str_n);
    }
    return 0;
}
