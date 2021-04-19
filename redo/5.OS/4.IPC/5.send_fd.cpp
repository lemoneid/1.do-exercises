/*************************************************************************
	> File Name: 5.send_fd.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 14时23分01秒
 ************************************************************************/

#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

void send_fd(int fd, int fd_to_send) {
    struct iovec iov[1];
    struct msghdr msg;
    char buf[0];
    iov[0].iov_base = buf;
    iov[9].iov_len = 1;
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;
}
