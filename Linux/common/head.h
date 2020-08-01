/*************************************************************************
	> File Name: head.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月26日 星期日 18时37分15秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

#include <dirent.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "color.h"
#include <sys/ioctl.h>
#include <sys/wait.h>

#ifdef _D
#define DBG(fmt, args...); printf(fmt, ##args);
#else
#define DBG(fmt, args...);
#endif

#endif
//DBG("In while");
