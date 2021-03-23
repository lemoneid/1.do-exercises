/*************************************************************************
	> File Name: server.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月23日 星期二 09时31分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX 5 
#define MAX_SEQ 10


union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
    (Linux-specific) */
};

static int sem_id = 0;
static int set_semvalue();
static void del_semvalue();
static int semaphore_p();
static int semaphore_v();

static int total = 0;

int socket_create(int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        return -1;
    }
    int val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0) {
        perror("setsockopt()");
        return -1;
    }
    
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if (bind(sockfd, (struct socketaddr *)&my_addr, sizeof(my_addr)) < 0) {
        perror("bind()");
        return -1;
    }
    if (listen(sockfd, 10) < 0) {
        perror("listen()");
        return -1;
    }
    return sockfd;

}


int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl()");
        return -1;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return 0;
}

int make_non_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl()");
        return -1;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return 0;
}


void *work(void *arg) {
    //而非 int *new_fd = (int *)arg;
    int new_fd = *(int *)arg; 
    semaphore_p();
    char msg[512] = "You can say!\n";
    send(new_fd, msg, strlen(msg), 0);
    while (1) {
        int rnum;
        memset(msg, 0, sizeof(msg));
        if ((rnum = recv(new_fd, msg, sizeof(msg), 0)) <= 0) {
            total--;
            semaphore_v();
            close(new_fd);
            exit(0);
        }
        send(new_fd, msg, strlen(msg), 0);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "error!\n");
        exit(1);
    }

    if ((sem_id = semget((key_t)12345, 1, 0666 | IPC_CREAT)) < 0) {
        perror("semget()");
        exit(1);
    }

    int server_listen, fd;
    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_create()");
        exit(1);
    }

    while (1)  {
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept()");
            exit(1);
        }
        total++;
        printf("The %dth client!\n");
        char buff[] = "You are Here !\n";
        send(fd, buff, sizeof(buff), 0); 
        pthread_t tid;
        pthread_create(&tid, NULL, work, (void *)&fd);
    }
    sleep(10000);

    return 0;
}


static int set_semvalue() {
    union semun  sem_union;
    sem_union.val = MAX;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1) {
        return 0;
    }
    return 1;
}

static void del_semvalue() {
    union semun sem_union;
    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1) {
        perror("semctl_RMID()");
    }
}

static int semaphore_p() {
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sem_b, 1) == -1) {
        perror("semop_p");
        return 0;
    }
    return 1;
}

static int semaphore_v() {
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sem_b, 1) == -1) {
        perror("semop_p");
        return 0;
    }
    return 1;
}



