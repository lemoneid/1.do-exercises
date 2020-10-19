/*************************************************************************
	> File Name: shell.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月18日 星期日 20时16分17秒
 ************************************************************************/


#include "head.h"
#include "shell.h"

extern struct ShellData arr[MAX_THREAD];


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static char *shell_conf[8] = {
"Proc",
"Disk",
"Mem",
"Cpu",
"User",
"Sysinfo",
}; 

static char *shell_exe[6] = {
"CheckProcess.sh", 
"DiskLog.sh", 
"MemLog.sh",
"CpuLog.sh",
"Users.sh",
"SysInfo.sh",
};
void init_shell(int n, cJSON *conf, const char *who, const char *config) {
    for (int i = 0; i < MAX_THREAD; ++i) {
        strcpy(arr[i].conf, shell_conf[i]);
        strcpy(arr[i].sh, shell_exe[i]);
        arr[i].time = get_json_array_valueint(conf, who, config, arr[i].conf);
    }
    return ;
}

void *doing_shell(void *arg) {
    //printf("%d %s %s", arr[i].time, arr[i].sh, arr[i].conf);
    while (1) {
          pthread_mutex_lock(&mutex);
    int ind = *(int *)arg;
    char filename[512];
    sprintf(filename, "./shell/%s >> ./log/%s", arr[ind].sh, arr[ind].conf);
    DBG(YELLOW"%s\n"NONE,filename);
    system(filename);
          pthread_mutex_unlock(&mutex);
    sleep(arr[ind].time);
    }
    return NULL;
}

void exe_pthread(int n) {
    int tmp_arg[MAX_THREAD] = {0};
    pthread_t tid[MAX_THREAD];
    for (int i = 0; i < n; ++i) {
        tmp_arg[i] = i;
        pthread_create(&tid[i], NULL, doing_shell, (void *)&tmp_arg[i]);
    }
    for (int i = 0; i < n; ++i) {
        pthread_join(tid[i], NULL);
    }
}




