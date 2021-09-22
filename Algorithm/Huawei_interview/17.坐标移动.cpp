/*************************************************************************
	> File Name: 17.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月18日 星期六 16时26分55秒
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

int main() {
    string str;
    while (cin >> str) {
        int x = 0, y = 0;
        vector<string> steps;
        int wordlen = 0;
        for (int i = 0; str[i]; i++) {
            while (str[i] != ';') {
                wordlen++, i++;
            }
            steps.push_back(str.substr(i - wordlen, wordlen));
            wordlen = 0;
        }
#ifdef _D
    for (auto cur : steps) cout << cur << endl;
#endif
        for (int i = 0; i < steps.size(); i++) {
            int num = 0, flag = 0;
            for (int j = 1; steps[i][j]; j++) {
                if (steps[i][j] < '0' || steps[i][j] > '9') {
                    flag = 1;
                    break;
                }
                num = num * 10 + steps[i][j] - '0';
            }
            if (flag) continue;
            switch(steps[i][0])//ASDW
            {
                case 'A': x -= num; break;
                case 'D': x += num; break;
                case 'W': y += num; break;
                case 'S': y -= num; break;
                default: break;
            }
        }
        cout << x << ',' << y << endl;
    }


    return 0;
}
