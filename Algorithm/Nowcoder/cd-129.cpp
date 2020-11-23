/*************************************************************************
	> File Name: cd-129.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 15时19分40秒
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
const long long MOD = 1 << 29;
typedef vector<vector<long long>> vector2;

vector2 multiMatrix(vector2 m1, vector2 m2) {
    vector2 res(m1.size(), vector<long long>(m2[0].size()));
    for (long long i = 0; i < m1.size(); ++i) {
        for (long long j = 0; j < m2[0].size(); ++j) {
            for (long long k = 0; k < m1[0].size(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector2 matrixPower(vector2 m, long long p) {
    vector2 res(m.size(), vector<long long>(m[0].size()));
    for (long long i = 0; i < m.size(); ++i) {
        res[i][i] = 1;
    }
    vector2 tmp = m;
    while (p) {
        if (p & 1) res = multiMatrix(res, tmp);
        tmp = multiMatrix(tmp, tmp);
        p >>= 1;
    }
    return res;
}

int main() {
    long long n, ans;
    cin >> n;
    if (n < 3) {
        cout << n << endl;
        return 0;
    }
    vector2 base = {{1, 1}, {1, 0}};
    vector2 res = matrixPower(base, n - 2);
    ans = (res[1][0]  + (res[0][0] * 2 % MOD)) % MOD;
    cout << ans << endl;
    return 0;
}
