/*************************************************************************
	> File Name: EP03-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 19时46分03秒
 ************************************************************************/

#include<cstdio>
#define max_m 600851475143LL   // int_64t

int main() {
    long long num = max_m, ans = 0;
    int i = 2;
    while(i *i <= num) {
        if(num % i == 0) ans = i;
        while( num % i == 0 ) num /= i;
        i++;
    }
    if(num != 1) ans = num;
    printf("%lld\n", num);
    return 0;
}
