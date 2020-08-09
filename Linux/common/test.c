/*************************************************************************
	> File Name: test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月08日 星期六 15时18分38秒
 ************************************************************************/

#include "head.h"

int main() {
    char * p = get_conf("./test.conf", "MYNAME");
    printf("%s", p);
    free(p);
    return 0;
}

