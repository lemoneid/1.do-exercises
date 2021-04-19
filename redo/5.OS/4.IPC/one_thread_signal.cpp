/*************************************************************************
	> File Name: one_thread_signal.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 14时41分54秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define handle_error_en(en, msg)\
    do {errno = en; perror(msg); exit(EXIT_FAILURE); } while (0);

static void *sig_thread(void *arg) {
    sigset_t *set = (sigset_t *) arg;
    int s, sig;
    while (1) {
        s = sigwait(set, &sig);
        if (s) handle_error_en(s, "sigwait");
        printf("Signal handling thread got signal : %d\n", sig);
    }
}

int main() {
    pthread_t thread;
    sigset_t set;
    int s;
    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGUSR1);
    s = pthread_sigmask(SIG_BLOCK, &set, NULL);
    if (s) handle_error_en(s, "pthread_sigmask");
    s = pthread_create(&thread, NULL, sig_thread, (void *)&set);
    if (s) handle_error_en(s, "pthread_create");
    pause();
    return 0;
}
