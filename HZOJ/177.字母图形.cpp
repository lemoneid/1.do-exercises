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
    string str;
    cin >> str;
    int l = str.size();
    for( int i = 0; i < 2 * l; i += 2 ){
        for( int j = 0; j < l; j++ ){
            cout << str[ ( 2 * l - i + j) % l ];
        }
        cout << endl;
    }
    return 0;
}
