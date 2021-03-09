/*************************************************************************
	> File Name: oj-261.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 09时57分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
#define MAX_N 1000
long long sum[MAX_N + 5];
long long f[MAX_N + 5];

int main() {
    long long n;
    char op[10];
    stack<long long> s1, s2;
    cin >> n;
    f[0] = 0x8000000000000000LL;
    while (n--) {
        cin >> op;
        switch (op[0]) {
            case 'I' : {
                long long x;
                cin >> x;
                s1.push(x);
                long long ind = s1.size();
                sum[ind] = sum[ind - 1] + x;
                f[ind] = max(f[ind - 1], sum[ind]);
            } break;
            case 'D' : {
                if (!s1.empty()) s1.pop();
            } break;
            case 'L' : {
                if (s1.empty()) break;
                s2.push(s1.top());
                s1.pop();
            } break;
            case 'R' : {
                if (s2.empty()) break;
                s1.push(s2.top());
                long long ind = s1.size();
                sum[ind] = sum[ind - 1] + s2.top();
                f[ind] = max(f[ind - 1], sum[ind]);
                s2.pop();
            } break;
            case 'Q' : {
                long long k;
                cin >> k;
                cout << f[k] << endl;
            } break;
        }
    }
    return 0;
}
