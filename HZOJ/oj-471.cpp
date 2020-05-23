/*************************************************************************
	> File Name: EP-471.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 19时59分09秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
#define max_n 100

char str1[max_n + 5], str2[max_n + 5];
int a[max_n + 5], b[max_n + 5], c[max_n * 2 + 5];

void carry(int *arr, int *len) {
    for (int i = 0; i < *len; ++i) {
        if (arr[i] < 10) continue;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
        *len += ((i + 1) == *len);
    }
    return ;
}
void output(int *arr, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    cout << endl;
    return ;
}
void solve(const char *str1, const char *str2) {
    memset(c, 0, sizeof(c));
    int len_a = strlen(str1), len_b = strlen(str2);
    int len;
    for (int i = 0; str1[i]; i++) a[len_a - i - 1] = str1[i] - '0';
    for (int i = 0; str2[i]; i++) b[len_b - i - 1] = str2[i] - '0';
    for (int i = 0; i < len_a; ++i) {
        for (int j = 0; j < len_b; ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    len = len_a + len_b - 1;
    carry(c, &len);
    output(c, len);
    return ;
}


int main() {
    while (scanf("%s%s", str1, str2) != EOF) {
        solve(str1, str2);
    }
    return 0;
}
