/*************************************************************************
	> File Name: 5.main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 21时12分27秒
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

//Linux printenv, export

void output(int argc, char **argv, char **env) {
    cout << argc << endl;
    for (int i = 0; i < argc; i++) cout << argv[i] << endl;
    cout << "--env--" << endl;
    for (int i = 0; env[i]; i++) {
        if (strncmp(env[i], "USERNAME=", 9) == 0) {
            if (strncmp(env[i] + 9, "worst", 5) == 0) {
                cout << "Welcome to beat the code" << endl;
                continue;
            } else {
                cout << "away" << endl;
            }
        }
    }
}

int main(int argc, char **argv, char **env) {
    output(argc, argv, env);
    return 0;
}
