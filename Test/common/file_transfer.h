/*************************************************************************
	> File Name: file_transfer.h
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 20 Sep 2020 06:34:24 PM CST
 ************************************************************************/

#ifndef _FILE_TRANSFER_H
#define _FILE_TRANSFER_H
void send_file(const char *filename, int sockfd);
void recv_file(int sockfd);
#endif
