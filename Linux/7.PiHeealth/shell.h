/*************************************************************************
	> File Name: shell.h
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月18日 星期日 20时15分31秒
 ************************************************************************/

#ifndef _SHELL_H
#define _SHELL_H
#define MAX_THREAD 6

struct ShellData{
    int time;
    char sh[50];
    char conf[50];
};
void init_shell(int n, cJSON *conf, const char *who, const char *config);
void exe_pthread(int n);

/*
"Proc" : 5,
"Disk" : 60,
"Mem" : 10,
"Cpu" : 10,
"User" : 120,
"Sysinfo" : 30

CheckProcess.sh  CpuLog.sh  DiskLog.sh  MemLog.sh  SysInfo.sh  Users.sh
*/

#endif
