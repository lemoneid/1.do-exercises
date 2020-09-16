/*************************************************************************
	> File Name: test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月16日 星期三 19时55分18秒
 ************************************************************************/

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <inttypes.h>

//192.168.0.1
//
char *my_inet_ntoa(struct in_addr in) {
    static char ip[20] = {0};
    uint8_t *p;
    p = (uint8_t *)&in.s_addr;
    sprintf(ip, "%d.%d.%d.%d\n", p[0], p[1], p[2], p[3]);
    return ip;
}

int main() {
    char input_ip[20] = {0};
    scanf("%s", input_ip);
    printf("input_ip = %s\n", input_ip);
    printf("uint32_t ip = %d\n", inet_addr(input_ip));
    struct in_addr in;
    in.s_addr = inet_addr(input_ip);
    printf("Ip After Change : %s\n", my_inet_ntoa(in));
    return 0;
}
