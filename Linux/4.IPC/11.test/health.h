/*************************************************************************
	> File Name: health.h
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月16日 星期五 18时23分49秒
 ************************************************************************/

#ifndef _HEALTH_H
#define _HEALTH_H
struct Share {
    int type; // 0: Master; 1: Salve;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};
#endif
