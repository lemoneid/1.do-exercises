/*************************************************************************
	> File Name: heart_beat.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月30日 星期五 17时48分35秒
 ************************************************************************/

#include "head.h"

extern struct User *rteam, *bteam;
extern int repollfd, bepollfd;
void heart_beat_team(struct User *team) {
    //遍历team数组，判断在线，则发送FT_HEART心跳包，flag--
  //判断palyer的flag是否减为0，减为0则判断为下线
    //数组中标记为offline-->online = 0
        //在从反应堆中注销IO  //del_event
}
void *heart_beat(void *arg) {
    //死循环，固定时间调用heart_beat_team
}
