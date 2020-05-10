/*************************************************************************
	> File Name: EP02-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 18时57分59秒
 ************************************************************************/

#include<cstdio>
#define max_m 4000000

int main() {
    int a = 1, b = 2;
    int sum = 2;
    while(a + b < max_m) {
        b = a + b;
        a = b - a;
        if(b & 1) continue;
        sum += b;
    }
    printf("%d\n", sum);
}
