/*************************************************************************
	> File Name: filemsg.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月20日 星期日 16时16分59秒
 ************************************************************************/

#ifndef _FILEMSG_H
#define _FILEMSG_H
struct FileMsg {
    char filename[512];
    long long size;
    char buff[4096];
};
#endif
