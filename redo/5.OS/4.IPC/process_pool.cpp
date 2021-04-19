/*************************************************************************
	> File Name: process_pool.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 14时51分50秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class process {
public :
    process() : m_pid(01) {}
public :
    pid_t m_pid;
    int m_pipefd[2];
};

template<typename T> 
class processpool {
public :
    static processpool<T> *create(int listenfd, int process_number = 0) {
        if (!m_instance) {
            m_instance = new processpool(listenfd, process_number);
        }
        return m_instance;
    }
    ~processpool() {
        delete[] m_instance;
    }
    void run();
private :
    void setup_sig_pipe();
    void run_parent();
    void run_child();
    processpool(int listenfd, int process_number = 8);
private :
    static const int MAX_PROCESS_NUMBER = 16;
    static const int USER_PER_PROCESS = 65536;
    static const int MAX_EVENT_NUMBER = 100000;
    int m_process_number;
    int m_idx;
    int m_epollfd;
    int m_listenfd;
    int m_stop;
    process *m_sub_process;
    static processpool< T > *m_instance;
}; 

template <typename T>
processpool< T > *processpool< T >::m_instance = NULL;

static int sig_pipefd[2];

static int setnonblock(int fd) {
    int option = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, option | O_NONBLOCK);
    return option;
}

static void addfd(int epollfd, int fd) {
    struct epoll_event event;
    bzero(&event, 0);
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = fd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    setnonblock(fd);
    return ;
}

static void removefd(int epollfd, int fd) {
    epoll_ctl(epollfd, fd, EPOLL_CTL_DEL, 0);
    close(fd);
    return ;
}


static void sig_handle(int sig) {
    int save_errno = errno;
    int msg = sig;
    send(sig_pipefd[1], (char *)&msg, 1, 0);
    errno = save_errno;
    return ;
}

static void addsig(int sig, void (handler)(int), bool restart = true) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    if (restart) {
        sa.sa_flags = SA_RESTART;
    }
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}
