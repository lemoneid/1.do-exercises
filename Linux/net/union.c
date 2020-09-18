/*************************************************************************
	> File Name: union.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月18日 星期五 18时22分54秒
 ************************************************************************/

#include <stdio.h>

union Data {
    int a;
    char b;
};

int main() {
    int c = 1;
    if (*(char *)&c == 1) {
        printf("小端!\n");
    } else {
        printf("大端!\n");

    }
    return 0;
}
