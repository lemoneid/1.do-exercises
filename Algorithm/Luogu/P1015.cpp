/*************************************************************************
	> File Name: P1015.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月10日 星期二 19时45分27秒
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
using namespace std;
const int maxN  = 105;
char sixt[20] = "0123456789ABCDEF";

int judge(string s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return s == tmp;
}

string add(int k, string b) {
    string a = b;
    int numa[maxN], numb[maxN], numc[maxN];
    memset(numc, 0, sizeof(numc));
    reverse(a.begin(), a.end());
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        if (isdigit(a[i])) numa[len - i] = a[i] - '0';
        else numa[len - i] = a[i] - 'A' + 10;
        if (isdigit(b[i])) numb[len - i] = b[i] - '0';
        else numb[len - i] = b[i] - 'A' + 10;
    }
    int x = 0, lenc = 1;
    while (lenc <= len) {
        numc[lenc] += numa[lenc] + numb[lenc];  
        numc[lenc + 1] = numc[lenc] / k;
        numc[lenc] %= k;
        lenc++;
    }
    if (numc[lenc + 1]) lenc++;
    while (numc[lenc] == 0) lenc--;
    string ans;
    for (int i = lenc; i > 0; --i) ans += sixt[numc[i]];
    return ans;
}

int main() {
    int n;
    string val;
    cin >> n >> val;   
    for (int i = 0; i < 31; ++i) {
        if (judge(val)) {
            cout << "STEP=" << i << endl;
            return 0;
        }
        val = add(n, val);
    }
    cout << "Impossible!" << endl;
    return 0;
}
