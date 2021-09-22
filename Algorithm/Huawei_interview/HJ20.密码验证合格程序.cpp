/*************************************************************************
	> File Name: HJ20.密码验证合格程序.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月18日 星期六 19时32分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

auto is_in = [](int a, int b) {
    return [=](int x) {
        return a <= x && x <= b;
    };
};

auto is_litte = is_in('a', 'z');
auto is_upper = is_in('A', 'Z');
auto is_digit = is_in('0', '9');

bool judge(string passwd) {

//))20Uq%0
#ifdef _D
    cout << "size" << endl;
#endif
    if (passwd.size() <= 8) return false;
    int tag[10] = {};
    for (int i = 0; passwd[i]; i++) {
        if (is_litte(passwd[i])) tag[0] = 1;
        else if (is_upper(passwd[i])) tag[1] = 1;
        else if (is_digit(passwd[i])) tag[2] = 1;
        else tag[3] = 1;
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += tag[i];
    }
#ifdef _D
    cout << "kind" << endl;
#endif
    if (sum  < 3) return false;

    //考虑长度为 3 的子字符串是否有重复
    int num = 0;
    for (int i = 0; i <= passwd.size() - 6; i++) {
        for (int j = i + 3; j <= passwd.size() - 3; j++) {
            num = 0;
            for (int k = 0; k < 3; k++) {
                if (passwd[i + k] == passwd[j + k]) num++;
            }
            if (num == 3) return false;
        }
    }
    return true;
        
}

int main() {
    string passwd;
    while (cin >> passwd) {
        cout << (judge(passwd) ? "OK" : "NG") << endl;
    }
    return 0;
}
