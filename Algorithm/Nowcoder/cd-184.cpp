/*************************************************************************
	> File Name: cd-184.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 15时44分04秒
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
const long long MOD = 1e9 + 7;
typedef vector<vector<long long>> vector2;

vector2 multiMatrix(vector2 m1, vector2 m2) {
    vector2 res(m1.size(), vector<long long>(m2[0].size()));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m2.size(); ++k) {
                res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

vector2 matrixPower(vector2 m, long long p) {
    vector2 res(m.size(), vector<long long>(m[0].size()));
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    }
    vector2 tmp = m;
    while (p) {
        if (p & 1) res = multiMatrix(res, tmp);  
        tmp  = multiMatrix(tmp, tmp);
        p >>= 1;
    }
    return res;
}

int main() {
    long long n;
    scanf("%lld", &n);
    if (n < 1) {
        printf("0\n");
        return 0;
    }
    if (n == 1 || n == 2) {
        printf("%lld\n", n);
        return 0;
    }
    vector2 base = {{1, 1}, {1, 0}};
    vector2 res = matrixPower(base, n - 2);
    long long ans = ((2 * res[0][0]) % MOD + res[1][0]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
