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
const int mod = 1e9+7;
#define vector2 vector<vector<int>>

void muliMatrix(vector2 &res, vector2 &tmp) {
    vector2 m1 = res;
    vector2 m2 = tmp;
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m2.size(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void print(vector2 &m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixPower(vector2 &m, vector2 &res,int p) {
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    };
    vector2 tmp = m;
    vector2 tmp1 = m;
    while (p) {
        if (p & 1) muliMatrix(res, tmp);
        tmp1 = tmp;
        muliMatrix(tmp, tmp1);
        print(tmp);
        p >>= 1;
    }
}




int main() {
    int n;
    cin >> n;
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }
    vector2 m = {{1, 1}, {1, 0}};
    vector2 res(m.size(), vector<int>(m[0].size()));
    matrixPower(m, res, n - 2);
    cout << res[0][0] + res[1][0] << endl;
    return 0;
}
