/*************************************************************************
	> File Name: EP27.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月07日 星期日 15时27分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100000
int tab[]={2, 3, 5, 7};

long long qpow(int a, int b, int r)  //(a^b)%r  快速幂取模
{
    long long ret = 1, tmp = a;
    while(b)
    {
        if (b&1)
            ret = ret*tmp%r;
        tmp = tmp*tmp%r;
        b >>= 1;
    }
    return ret; 
}
bool  Miller_Rabbin(int n, int a)//米勒拉宾素数测试 
{
    int r = 0, s = n-1, j;
    long long k;
    if(n%a == 0)    return false;
    while((s&1) == 0)
    {
        s >>= 1;
        r++;
    }
    k = qpow(a, s, n);
    if(k == 1)  return true;
    for (j = 0; j < r; j++, k=k*k%n)
        if (k == n-1)
            return true;
    return false;
}
bool is_prime(int n)//判断是否是素数 
{
    for (int i = 0; i < 4; i++)
    {
        if (n == tab[i])
            return true;
        if (!Miller_Rabbin(n, tab[i]))
            return false;
    }
    return true;
}

int get_len(int a, int b) {
    int cnt = 2;
    for (int n = 2; ; ++n) {
        long long temp = n * n + a * n + b;
        if (temp < 0) break;
        if (is_prime(temp)) break;
        cnt += 1;
    } 
    return cnt;
}

int main() {
    int x, y, len = 0;
    for (int b = 2; b < 1000; b++) {
        if (is_prime(b)) continue;
        for (int a = -999; a < 1000; a += 2) {
            if (a + b + 0 < 0) continue;
            if (is_prime(a + b + 1)) continue;
            int temp = get_len(a, b);
            if (temp <= len) continue;
            x = a, y = b, len = temp;
        }
    }
    printf("x = %d, y = %d, len = %d\n", x, y, len);
    cout << x * y <<endl;
    return 0;
}
