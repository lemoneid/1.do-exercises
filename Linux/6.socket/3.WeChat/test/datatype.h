/*************************************************************************
	> File Name: datatype.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月25日 星期五 08时28分00秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
struct FileMsg {
    char name[512];
    char buff[4096];
    long long size;
};
#define handle_error(msg) \
    do{perror(msg); exit(EXIT_FAILURE);}while(0);

#endif
