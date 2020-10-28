/*************************************************************************
	> File Name: EP14-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 15时18分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int max_n = 1000000;

typedef long long ll;

int keep[max_n + 5] = {0};

ll get_len(ll n) {
    if (n == 1) return 1;
    if (n < max_n && keep[n]) return keep[n];
    ll ret;
    if (n & 1) ret = get_len(3 * n + 1) + 1;
    else ret = get_len(n >> 1) + 1;
    if (n < max_n) keep[n] = ret;
    return ret;
}

int main() {
    ll ans = 0, len = 0, temp = 0;
    for (int i = 1; i < max_n; ++i) {
        temp = get_len(i);
        if (temp <= len) continue;
        ans = i;
        len = temp;
    }    
    cout << ans << " = " << len << endl;
    return 0;
}
