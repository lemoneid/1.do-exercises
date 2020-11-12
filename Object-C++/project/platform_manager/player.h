/*************************************************************************
	> File Name: player.h
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 19时37分20秒
 ************************************************************************/

#ifndef _PLAYER_H
#define _PLAYER_H

#define NONEISIT 1000
#define 

#include <string>
using namespace std;

class Player {
    private :
        string userName;
        string nickName;
        unsigned int loginAccount;
        string loginPassword = "123456";
        bool sex;
    

    public:
        Player();
        -Player();
        void login();
        boll verfileAccount();
}

#endif
