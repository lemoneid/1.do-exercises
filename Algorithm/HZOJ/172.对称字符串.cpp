/*************************************************************************
	> File Name: 176.寻找字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2020 02:42:50 PM CST
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str;
    string tag = "A";
    for( int i = 0; i < n; i++ ){
        str = str + tag + str;
        tag[0]++;
    }
    cout << str;
    return 0;
}
