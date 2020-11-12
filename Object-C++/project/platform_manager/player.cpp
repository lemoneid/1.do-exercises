/*************************************************************************
	> File Name: player.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 19时36分34秒
 ************************************************************************/
 #include "player.h"
 Player::Player() {

 }

 Player::-Player() {

 }

void Player::login() {
    cout << "input Acount" << endl;
    unsigned int inputAccount;
    cin >> inputAccount;
    bool result = this->verfileAccount(inputAccount);
    if (result == false) {
        ErrorMessage meg;
        meg.code = NONEISTI;
        meg.errorDiscription() = "no have the Account";
    } else {

    }
}

bool Player::verfileAccount(unsigned int inputAccount) {
    return inputAccount == loginAccount;
}
