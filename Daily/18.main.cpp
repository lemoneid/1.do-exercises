/*************************************************************************
	> File Name: 18.main.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 21 May 2020 08:46:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void output(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("%s\n",argv[i]);
    }
    return ;
}

int main(int argc, char *argv[]) {
    output(argc, argv);
    return 0;
}
