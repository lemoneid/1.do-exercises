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
    string name;
    int a, b, c, d,sum;
};
bool cmp1 ( student s1, student s2 ){
    if( s1.a == s2.a )
        return s1.name < s2.name;
    return s1.a > s2.a;
}
bool cmp2 ( student s1, student s2 ){
    if( s1.b == s2.b )
        return s1.name < s2.name;
    return s1.b > s2.b;
}
bool cmp3 ( student s1, student s2 ){
    if( s1.c == s2.c )
        return s1.name < s2.name;
    return s1.c > s2.c;
}
bool cmp4 ( student s1, student s2 ){
    if( s1.d == s2.d )
        return s1.name < s2.name;
    return s1.d > s2.d;
}
bool cmp5 ( student s1, student s2 ){
    if( s1.sum == s2.sum )
        return s1.name < s2.name;
    return s1.sum > s2.sum;
}






int main (){
    int temp, a, b, c, d;
    int n; 
    struct student stu[1005];
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> stu[i].name;
        cin >> stu[i].a >> stu[i].b >> stu[i].c >> stu[i].d;
        stu[i].sum = stu[i].a +stu[i].b + stu[i].c + stu[i].d;
    }
    sort( stu, stu + n, cmp1 );
    for( int i = 0; i < 4; i++ ){
        if(i)
            cout << " ";
        cout << stu[i].name;
    }
    cout << endl;

    sort( stu, stu + n, cmp2 );
    for( int i = 0; i < 4; i++ ){
        if(i)
            cout << " ";
        cout << stu[i].name;
    }
    cout << endl;
    sort( stu, stu + n, cmp3 );
    for( int i = 0; i < 4; i++ ){
        if(i)
            cout << " ";
        cout << stu[i].name;
    }
    cout << endl;
    sort( stu, stu + n, cmp4 );
    for( int i = 0; i < 4; i++ ){
        if(i)
            cout << " ";
        cout << stu[i].name;
    }
    cout << endl;
    sort( stu, stu + n, cmp5 );
    for( int i = 0; i < 4; i++ ){
        if(i)
            cout << " ";
        cout << stu[i].name;
    }
    cout << endl;

    return 0;
}
