/*************************************************************************
	> File Name: head.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 13时20分01秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include "color.h"

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <sys/shm.h>
#include <signal.h>


#ifdef _D
#define DBG(frm, args...) printf(frm, ##args);
#else
#define DBG(frm, args...)
#endif

#endif
