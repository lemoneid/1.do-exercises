/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 03 May 2020 02:19:28 PM CST
 ************************************************************************/

#include<cstdio>
#include<algorithm>
#define DEBUG
#ifdef DEBUG
#define log(frm, args...) {\
    printf("[%s : %d]%s", __func__, __LINE__,#args);\
    printf(frm,##args);\
    printf("\n");\
}

#else
#define log(frm, args...)
#endif

int main() {
    log("Hello world");
}

