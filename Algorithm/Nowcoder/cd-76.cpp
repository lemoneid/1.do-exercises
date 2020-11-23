/*************************************************************************
	> File Name: cd-76.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 20时41分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,n2;scanf("%d",&n);
    if(!n){
        printf("Zero\n");
        printf("零");
        return 0;
    }
    if(n == INT_MIN){
        printf("Negative, Two Billion, One Hundred Forty Seven Million, Four Hundred Eighty Three Thousand, Six Hundred Forty Eight\n");
        printf("负二十一亿四千七百四十八万三千六百四十八");
        return 0;
    }
    n2 = n;
    string _19[]={ "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
    "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
    "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Sixteen ",
    "Eighteen ", "Nineteen " };
    string _20[]={ "Twenty ", "Thirty ", "Forty ", "Fifty ","Sixty ", "Seventy ", "Eighty ", "Ninety " };
    string rk[]={"Billion, ","Million, ","Thousand, "};
    string res;
    if(n < 0){
        res += "Negative, ";
        n = -n;
    }
    int k = 1e9,i = 0;
    while(k){
        int t = n/k;
        if(t){
            if(t/1000) res += _19[t/1000-1] + "Thousand ";
            t %= 1000;
            if(t/100) res += _19[t/100-1] + "Hundred ";
            if(t%100 >= 20){
                res += _20[t%100/10-2];
                if(t%10) res += _19[t%10-1];
            }else if(t%100) res += _19[t%100-1];
            if(i < 3) res += rk[i];
        }
        n %= k;i++;
        k /= 1000;
    }
    
    cout<<res<<'\n';
    res = "";
    string c[]= { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
    string rc[]= {"亿","万"};
    n = n2;
    i = 0;
    if(n < 0){
        res += "负";
        n = -n;
    }
    k = 1e8;
    bool ffff = false;
    while(k){
        int t = n/k;
        if(t){
            bool f = false,fff = false,ff = false;
            if(t/1000) {
                res += c[t/1000-1]+"千";
                fff = true;
            }else if(ffff) res += "零";
            t %= 1000;
            if(t/100) res += c[t/100-1]+"百";
            else f = true;
            t %= 100;
            if(t/10) {
                res += (fff&&f?"零":"")+(!fff||!f||t/10>1?c[t/10-1]:"")+"十";
                ff = false;
            }
            t %= 10;
            if(t) res += (ff?"零":"")+c[t-1];
            if(i < 2) res += rc[i];
            ffff = true;
        }
        n %= k;
        i++;k /= 10000;
    }
    cout<<res;
}
