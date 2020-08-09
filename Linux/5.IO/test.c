/*************************************************************************
	> File Name: ../5.IO/test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月08日 星期六 14时32分17秒
 ************************************************************************/

#include "head.h"
int main() {
    char buff[512] = {0};
    /*
    int flag = fcntl(0, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(0, F_SETFL, flag);
    */
    //make_non_block(0);
    // 0 1 2 大多数是一个文件，在/dev/pts中
    make_block(3);
    scanf("%s", buff);
    printf("%s", buff);

    make_non_block(3);
    scanf("%s", buff);
    printf("%s", buff);
    return 0;
}
