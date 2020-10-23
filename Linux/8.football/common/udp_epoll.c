/*************************************************************************
	> File Name: udp_epoll.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月21日 星期三 19时15分00秒
 ************************************************************************/

#include "head.h"
extern struct User *bteam, *rteam;
extern int port;

#define MAX 6

void add_event_ptr(int epollfd, int fd, int events, struct User *user) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.ptr = (void *)user;
    DBG(PINK"Main Reactor"NONE " : adding %s to main reacator\n", user->name);
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        perror("epoll_ctl()");
        exit(1);
    }
}

void del_event(int epollfd, int fd) {
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
    DBG(PINK"Main Reactor"NONE " : deling %s to main reacator\n", user->name);

}

int udp_connect(struct sockaddr_in *client){
    int sockfd;
    //调用任务2创建一个udp套接字
    //connect到client
    //注意，在这里你应该至少用两个if判断是否成功，必要的安全判断，是程序稳定运行的前提，也是写程序时一定要注意的细节，减少调试压力
    return sockfd;
}

//user指针需要在调用之前创建一个User结构体，然后将其地址传入，这是一个输出参数
int udp_accept(int fd, struct User *user) {
    int new_fd, ret;
    struct sockaddr_in client;
    struct LogRequest request;
    struct LogResponse response;
    socklen_t len = sizeof(client);
    //初始化必要的结构体
    ret = recvfrom(fd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&client, &len);
    //判断ret，也就是收到的字节数如果不等于LogRequest报文的大小
        //设置response报文，并告知对方此msg："Login failed with Data errors!
        //注意，你应该直接发送response报文
        //return -1
    new_fd = udp_connect(&client);
    //判断如果new_fd为-1，应该return -1
    //拷贝request中的name到user指向的结构体中，当然还有team，fd等
    //send告知客户端：" Login Success, Enjoy Yourself"
    return new_fd;
}

void add_to_sub_reactor(struct User *user);

int check_online(struct LogRequest *request){
    for (int i = 0; i < MAX; i++) {
    //判断两个队伍中是否有同名用户，有的话返回1
    
    }
    return 0;
}
