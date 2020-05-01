/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct student{
    int h, num = 0, id;
};
bool cmp1 ( student s1, student s2 ){
    return s1.h < s2.h;
}

bool cmp2( student s1, student s2 ){
    return s1.id < s2.id;
}

int main (){
    student s[100005];
    int a[100005] = {0};
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < n; i++ ){
        cin >> s[i].h;
        s[i].id = i;
    }
    for( int i = 0; i < m; i++ ){
        cin >> a[i];
    }
    sort( s, s + n, cmp1 );
    sort( a, a + m );
    int j = 0;
    for( int i = 0; i < n; i++  ){
        
        for( ; a[j] <= s[i].h && j < m; j++ ){
                s[i].num++;
        }
    }
    sort( s, s + n, cmp2 );
    for( int i = 0; i < n; i++ ){
        cout << s[i].num << endl;
    }
    return 0;
}
