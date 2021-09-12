#include <unistd.h>
extern char **environ;
int execl(const char *pathname, const char *arg, ... /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
int execle(const char *pathname, const char *arg, ... /*, (char *) NULL, char *const envp[] */);
int execv(const char *pathname, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[], char *const envp[]);
#include＜sys/sem.h＞
/*该结构体用于描述IPC对象（信号量、共享内存和消息队列）的权限*/
struct ipc_perm
{
    key_t key;/*键值*/
    uid_t uid;/*所有者的有效用户ID*/
    gid_t gid;/*所有者的有效组ID*/
    uid_t cuid;/*创建者的有效用户ID*/
    gid_t cgid;/*创建者的有效组ID*/
    mode_t mode;/*访问权限*/
    /*省略其他填充字段*/
}
struct semid_ds
{
    struct ipc_perm sem_perm;/*信号量的操作权限*/
    unsigned long int sem_nsems;/*该信号量集中的信号量数目*/
    time_t sem_otime;/*最后一次调用semop的时间*/
    time_t sem_ctime;/*最后一次调用semctl的时间*/
    /*省略其他填充字段*/
};
union semun
{
    int val;/*用于SETVAL命令*/
    struct semid_ds*buf;/*用于IPC_STAT和IPC_SET命令*/
    unsigned short*array;/*用于GETALL和SETALL命令*/
    struct seminfo*__buf;/*用于IPC_INFO命令*/
};
struct seminfo
{
    int semmap;/*Linux内核没有使用*/
    int semmni;/*系统最多可以拥有的信号量集数目*/
    int semmns;/*系统最多可以拥有的信号量数目*/
    int semmnu;/*Linux内核没有使用*/
    int semmsl;/*一个信号量集最多允许包含的信号量数目*/
    int semopm;/*semop一次最多能执行的sem_op操作数目*/
    int semume;/*Linux内核没有使用*/
    int semusz;/*sem_undo结构体的大小*/
    int semvmx;/*最大允许的信号量值*/
    /*最多允许的UNDO次数（带SEM_UNDO标志的semop操作的次数）*/
    int semaem;
};
struct shmid_ds
{
    struct ipc_perm shm_perm;/*共享内存的操作权限*/
    size_t shm_segsz;/*共享内存大小，单位是字节*/
    __time_t shm_atime;/*对这段内存最后一次调用shmat的时间*/
    __time_t shm_dtime;/*对这段内存最后一次调用shmdt的时间*/
    __time_t shm_ctime;/*对这段内存最后一次调用shmctl的时间*/
    __pid_t shm_cpid;/*创建者的PID*/
    __pid_t shm_lpid;/*最后一次执行shmat或shmdt操作的进程的PID*/
    shmatt_t shm_nattach;/*目前关联到此共享内存的进程数量*/
    /*省略一些填充字段*/
};


