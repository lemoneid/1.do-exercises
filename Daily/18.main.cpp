/************************************************************************
	> File Name: 18.main.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 21 May 2020 08:46:10 PM CST
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

void output(int argc, char *argv[], char **env) {
    cout << argc << endl;
    for (int i = 0; i < argc; ++i) {
        printf("%s\n",argv[i]);
    }
    for (int i = 0; env[i]; ++i) {
        //printf("env[%d] = %s\n", i, env[i]);
        if (strncmp(env[i], "USERNAME=", 9) == 0) {
            if (strncmp(env[i] + 9, "worst", 5) == 0) {
                cout << "Welcome to beat the code" << endl;
                continue;
            }
            cout << "Please go away" << endl;
        }
    }
    return ;
}

int main(int argc, char *argv[], char **env) {
    output(argc, argv, env);
    return 0;
}
