/*************************************************************************
	> File Name: cd-47-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 10时17分45秒
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
#define mod 1000000007

bool isValid(string p) {
    if ((p.size() & 1) == 0) return false;
    for (int i = 0, j = 1; i < p.size(); i += 2, j += 2) {
        if (p[i] != '0' && p[i] != '1') return false;
        if (j < p.size() && p[j] != '&' && p[j] != '|' && p[j] != '^') return false; 
    }
    return true;
}

long long func(string p, bool desire) {
    if (p.size() == 0) return 0;
    if (!isValid(p)) return 0;
    int len = p.size();
    long long **t = (long long **)calloc(sizeof(long long *), (len + 5));
    long long **f = (long long **)calloc(sizeof(long long *), (len + 5));
    for (long long i = 0; i < len + 5; ++i) {
        t[i] = (long long *)calloc(sizeof(long long) , len + 5);
        f[i] = (long long *)calloc(sizeof(long long) , len + 5);
    }
    
    for (int i = 0; i < len; i += 2) {
        t[i][i] = p[i] == '0' ? 0 : 1;
        f[i][i] = p[i] == '1' ? 0 : 1;
    }
    for (int i = 2; i < len; i += 2) {
        for (int j = i - 2; j >= 0; j -= 2) {
            for (int k = j; k < i; k += 2) {
                switch (p[k + 1]) {
                    case '&' : 
                        t[j][i] += (t[j][k] * t[k + 2][i]) % mod;
                        f[j][i] += (f[j][k] * (f[k + 2][i] + t[k + 2][i]) + t[j][k] * f[k + 2][i]) % mod;
                        break;
                    case '|' : 
                        t[j][i] += (t[j][k] * (f[k + 2][i] + t[k + 2][i]) + f[j][k] * t[k + 2][i]) % mod;
                        f[j][i] += (f[j][k] * f[k + 2][i]) % mod;
                        break;
                    case '^' :
                        t[j][i] += (t[j][k] * f[k + 2][i] + f[j][k] * t[k + 2][i]) % mod;
                        f[j][i] += (t[j][k] * t[k + 2][i] + f[j][k] * f[k + 2][i]) % mod;
                        break;
                }
                t[j][i] %= mod;
                f[j][i] %= mod;
            }
        }
    }
    long long ans = desire == true? t[0][len - 1] % mod : f[0][len - 1] % mod;
    free(t);
    free(f);
    return ans;
}


int main() {
    string p, desire;
    cin >> p >> desire;
    long long ans = func(p, desire == "true");
    cout << ans << endl;
    return 0;
}
