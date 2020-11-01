/*************************************************************************
	> File Name: server_re_draw.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月01日 星期日 17时18分51秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
extern struct User *rteam, *bteam;
extern WINDOW *Football, *Football_t;
extern struct BallStatus ball_status;
extern struct Bpoint ball;
void re_drew_ball() {
    //根据ball_status里记录的加速度，和上次re_drew时的速度，算出本次球应该移动的时间
    //加速度保持不变，速度更新
    //需要注意的是，当判断到速度减为，ball_status里的速度和加速度都清空
    //同样需要注意的时，球如果超过球场边界，则判定为出界，球停止到边界即可
}
void  re_drew_player(int team, char *name, struct Point *loc) {
    //根据team，切换颜色
  //在loc位置打印player，并显示姓名
}
void re_drew_team(struct User *team) {
    //在team数组中，循环遍历用户，调用re_drew_palyer
}
void re_drew(){
    //分别调用re_drew_team、re_drew_ball
}
