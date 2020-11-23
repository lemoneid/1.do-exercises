/*************************************************************************
	> File Name: 183.斐波那契数列问题的递归和动态规划.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月27日 星期日 11时24分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const long long mod = 1e9+7;
typedef vector<vector<long long>> vector2;

vector2  muliMatrix(vector2 m1, vector2 m2) {
    vector2 res(m1.size(), vector<long long>(m2[0].size()));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m2.size(); ++k) {
                res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

void print(vector2 &m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

vector2 matrixPower(vector2 m, long long p) { 
    vector2 res(m.size(), vector<long long>(m[0].size()));
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    };
    vector2 tmp = m;
    while (p) {
        if (p & 1) res = muliMatrix(res, tmp);
        tmp = muliMatrix(tmp, tmp);
        p >>= 1;
    }
    return res;
}




int main() {
    long long n;
    scanf("%lld", &n);
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }
    vector2 m = {{1, 1}, {1, 0}};
    vector2 res = matrixPower(m, n - 2);
    printf("%lld\n", (res[0][0] + res[1][0]) % mod);
    return 0;
}
