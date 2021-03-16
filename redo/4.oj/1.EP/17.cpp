/*************************************************************************
	> File Name: 17.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 19时24分15秒
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

int GetLetterNum(int i) {
    static int LN20[20] = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    static int LN_shi[20] = {
        0, 0, 6, 6, 5, 5, 7, 6, 6
    };
    if (i < 20) return LN20[i];
    else if (i < 100) {
        return LN_shi[i / 10] + LN20[i %  10];
    } else if (i < 1000) {
        int temp = GetLetterNum(i % 100);
        if (temp != 0) temp += 3;
        return temp + LN20[i / 100] + 7;
    } else if (i == 1000) {
        return 11;
    } else {
        return 0;
    }
} 

int main() {


    return 0;
}
