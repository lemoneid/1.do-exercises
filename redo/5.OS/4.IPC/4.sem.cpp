/************************************************************************
	> File Name: sem.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 13时06分28秒
 ************************************************************************/

#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int* array;
    struct seminto *__buf;
};

void pv(int sem_id, int op) {
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = op;
    sem_b.sem_flg = SEM_UNDO;
    semop(sem_id, &sem_b, 1);
}

int main(int argc, char *argv[]) {
    int sem_id = semget(IPC_PRIVATE, 1, 0666);
    printf("the sem_id is %d\n", sem_id);
    union semun sem_un;
    sem_un.val = 1;
    semctl(sem_id, 0, SETVAL, sem_un);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("child try to get binary sem\n");
        pv(sem_id, -1);
        printf("child get the sem and release it after 5 seconds\n");
        sleep(1);
        pv(sem_id, 1);
        exit(0);
    } else {
        printf("parent try to get binary sem\n");
        pv(sem_id, -1);
        printf("parent get the sem and release it after 5 seconds\n");
        sleep(1);
        pv(sem_id, 1);
    }
    waitpid(pid, NULL, 0);
    semctl(sem_id, 0, IPC_RMID, sem_un);

    return 0;
}
