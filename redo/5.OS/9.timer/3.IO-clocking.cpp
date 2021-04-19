/*************************************************************************
	> File Name: 3.IO-clocking.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月14日 星期三 20时32分05秒
 ************************************************************************/

#include "head.h"

#define TIMEOUT 5000
int timeout = TIMEOUT;
time_t start = time(NULL);
time_t end = time(NULL);


int solve() {

    int epollfd = epoll_create(1);
while (1) {
    printf("the time out is now %d mil-seconds\n", timeout);
    start = time(NULL);
    end = time(NULL);

    int nfds = epoll_wait(epollfd, NULL, 0, timeout);
    if (nfds < 0 && (errno != EINTR)) {
        perror("epollwait");
        break;
    }
    //timeout
    if (nfds == 0) {
        //do timeout task
        timeout = TIMEOUT;
        continue;
    }

    //更新timeout
    end = time(NULL);
    timeout -= (end - start) * 1000;

    if (timeout <= 0) {
        //do timeout task
        timeout = TIMEOUT;
    }

    return 0;
}

}
