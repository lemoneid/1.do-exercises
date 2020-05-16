/*************************************************************************
	> File Name: 16.log.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月14日 星期四 20时15分41秒
 ************************************************************************/

#include <stdio.h>
//#define DEBUG
#ifdef DEBUG
#define log(frm, args...) {\
    printf("[%s : %d] %s ", __func__, __LINE__, #args);\
    printf(frm, ##args);\
    printf("\n");\
}
#else
#define log(frm, args...)
#endif

#define contact(a, b) a##b

int main() {
    int a = 3, abc, def;
    int abcdef = 0;
    log("%d", abcdef);
    log("%d", a);
    log("hello world");
    contact(abc, def) = 123;
    log("%d", abcdef);
    return 0;
}
