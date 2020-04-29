/*************************************************************************
	> File Name: 176.寻找字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2020 02:42:50 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int main (){
    char s1[10001],  s2[1001];
    int l1 = strlen(s1), l2 = strlen(s2);
    int cnt = 0;
    cin >> s1 >> s2;
    for( int i = 0; i < l2 - l1; i++ ){
        if( strncmp( s2, &s1[i], l2 ) == 0 ){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
