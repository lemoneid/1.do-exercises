/*************************************************************************
	> File Name: 176.寻找字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2020 02:42:50 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main (){
    char s1[1005],  s2[1005];
    int cnt = 0;
    fgets(s1, 1005, stdin);
    fgets(s2, 1005, stdin);
    int l1 = strlen(s1), l2 = strlen(s2);
    for( int i = 0; i <= l1 - l2; i++ ){
        if( strncmp( s2, &s1[i], l2 ) == 0 ){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
