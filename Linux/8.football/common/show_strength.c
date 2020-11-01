/*************************************************************************
	> File Name: show_strength.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月01日 星期日 16时47分57秒
 ************************************************************************/

#include "head.h"
//客户端中，按下空格键，调用此函数
extern WINDOW *Write;
extern int sockfd;
void show_strength() {
    //在Write窗口中，显示踢球力度条，光标在进度条上快速移动
    //设置0文件为非阻塞IO
    //while 等待空格或者'k'键的按下，如果按下退出，取得当前的strength
    //通过sockfd向服务端发送控制信息，踢球
}
