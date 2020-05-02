/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    int n, x, cnt = 0, boy = 0, girl = 0;
    long long sum = 0, temp;
    char ch;
    string s;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> ch;
        if( ch == 'i' ){
            cin >> s;
            x = s[s.size() - 2] - 48;
            x & 1 ? boy++ : girl++;
        }else if( ch == 'q' ){
            cnt++;
            cin >> temp;
            sum += temp;
        }
    }
    cout << boy << " " << girl << " " << (sum ? sum / cnt : 0) ;
    return 0;
}




