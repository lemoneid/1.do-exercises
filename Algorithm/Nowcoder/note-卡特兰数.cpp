/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 15时43分26秒
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
#define ll long long
const ll mod=1000000007;
ll n,inv[10007],last,now=1;
int main() {
    scanf("%lld",&n);
    if(n<1||n>10000) return puts("error"),0;
    n++;
    inv[1]=1;
    //线性预处理
    for(int i=2;i<=n+1;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
     // 线性求逆元 inv[i]=-(mod/i)*inv[i%mod]
    for(int i=2;i<=n;i++) {
        last=now;
        now=last*(4LL*i-2LL)%mod*inv[i+1]%mod;
        cout << last << "--" << last * inv[i + 1] << endl;
        
    }
    printf("%lld\n",last);
    return 0;
}
