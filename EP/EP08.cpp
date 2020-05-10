/*************************************************************************
	> File Name: EP08.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 20时23分47秒
 ************************************************************************/

#include<cstdio>
#include<string.h>
#define max_n 1000

char num[max_n + 5];

int main() {
    int len = 0;
    while(~scanf("%s", num + len)) len += strlen(num + len);
    long long ans = 0, p = 1, zero = 0;
    for (int i = 0; num[i]; i++){
        num[i] -= '0';
        if (num[i]) p *= num[i];
        else zero += 1;
        if (i < 13) continue;
        if (num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if (zero == 0 && p > ans ) ans = p; 
    }
    printf("%lld\n", ans);
    return 0;
}
