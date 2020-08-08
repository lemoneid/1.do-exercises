/*************************************************************************
	> File Name: test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 15时26分40秒
 ************************************************************************/

#include "head.h"
#include "my_popen.h"

int main() {
    FILE *fp;
    char buff[1024] = {0};
    //报错512 和 2的关系 
    if ((fp = m_popen("ls /etc", "r")) == NULL) {
        perror("m_open()");
        exit(1);
    }

    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
        bzero(buff, sizeof(buff));
    } 
    
    int status = m_pclose(fp);
    printf("status : %d\n", status);
    return 0;

}
